import json
import os
import sys
import hashlib

# To be used in conjunction with the RPKG-Tool function dev_extract_all_entities_to_qn
# Example: rpkg-cli.exe -dev_extract_all_entities_to_qn H:\HITMAN3\Runtime\ -output_path r:\AllEntitiesInH3v3.140.0
# Outputs pins.json in the 'wiki pin search' format, and one in a hash-keyed format

pins = {}
entities = {}

def CalculateIOIHash(ioiString):
    if ioiString.startswith("["):
        return "00" + hashlib.md5(ioiString.lower().encode()).hexdigest()[2:16].upper()
    else:
        return ioiString

def recordPin(factory, pin, pinDir):
    global pins
    factoryHash = CalculateIOIHash(factory)
    if factoryHash not in pins:
        pins[factoryHash] = {}
        pins[factoryHash]["path"] = factory
        pins[factoryHash]["in"] = []
        pins[factoryHash]["out"] = []
    if pin not in pins[factoryHash][pinDir]:
        pins[factoryHash][pinDir].append(pin)

def processPin(entity, ref, pin, pinDir):
    global entities
    if "ref" in ref and "externalScene" in ref:
        entityHash = CalculateIOIHash(ref["externalScene"])
        recordPin(entities[entityHash]["entities"][ref["ref"]]["factory"], pin, pinDir)
    elif "ref" in ref:
        recordPin(entities[entity]["entities"][ref["ref"]]["factory"], pin, pinDir)
    else:
        recordPin(entities[entity]["entities"][ref]["factory"], pin, pinDir)

# load all entities in memory as QN JSONs
for root, dirs, files in os.walk("AllEntitiesInH3v3.140.0"):
    dirs.sort()
    files.sort()
    for file in files:
        if file.endswith(".entity.json"):
            with open(root + "/" + file, "r") as f:
                entity = json.load(f)
                entities[file[:16]] = entity

for entity in entities:
    for e in entities[entity]["entities"]:
        if "events" in entities[entity]["entities"][e]:
            for pin1 in entities[entity]["entities"][e]["events"]:
                for pin2 in entities[entity]["entities"][e]["events"][pin1]:
                    for ref in entities[entity]["entities"][e]["events"][pin1][pin2]:
                        processPin(entity, e, pin1, "out")
                        processPin(entity, ref, pin2, "in")
        if "inputCopying" in entities[entity]["entities"][e]:
            for pin1 in entities[entity]["entities"][e]["inputCopying"]:
                for pin2 in entities[entity]["entities"][e]["inputCopying"][pin1]:
                    for ref in entities[entity]["entities"][e]["inputCopying"][pin1][pin2]:
                        processPin(entity, e, pin1, "in")
                        processPin(entity, ref, pin2, "in")
        if "outputCopying" in entities[entity]["entities"][e]:
            for pin1 in entities[entity]["entities"][e]["outputCopying"]:
                for pin2 in entities[entity]["entities"][e]["outputCopying"][pin1]:
                    for ref in entities[entity]["entities"][e]["outputCopying"][pin1][pin2]:
                        processPin(entity, e, pin1, "out")
                        processPin(entity, ref, pin2, "in")
    if "pinConnectionOverrides" in entities[entity]:
        for override in entities[entity]["pinConnectionOverrides"]:
            processPin(entity, override["fromEntity"], override["fromPin"], "out")
            processPin(entity, override["toEntity"], override["toPin"], "in")
    if "pinConnectionOverrideDeletes" in entities[entity]:
        for override in entities[entity]["pinConnectionOverrideDeletes"]:
            processPin(entity, override["fromEntity"], override["fromPin"], "out")
            processPin(entity, override["toEntity"], override["toPin"], "in")

for pin in pins:
    pins[pin]["in"].sort()
    pins[pin]["out"].sort()

pinsList = []

for pin in pins:
    pinsList.append({
        "hash": pin,
        "path": pins[pin]["path"],
        "in": pins[pin]["in"],
        "out": pins[pin]["out"]
        })

with open("pins.json", "w", encoding="utf-8") as f:
    json.dump(pinsList, f, indent=4)

with open("pins_keyed.json", "w", encoding="utf-8") as f:
    json.dump(pins, f, indent=4)