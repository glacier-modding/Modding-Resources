import json
import os
import sys
import secrets
import struct
from pathlib import Path
from enum import Enum
import hashlib

class FileType(Enum):
	HASH = 0
	META = 1
	JSON = 2

hashData = []
hashMap = {}
hashList = {}

def CalculateIOIHash(ioiString):
	return "00" + hashlib.md5(ioiString.lower().encode()).hexdigest()[2:16].upper()

def getNewHash():
	global hashList
	while True:
		newHash = "00" + secrets.token_hex(7).upper()
		if newHash not in hashList:
			return newHash

if len(sys.argv) < 3:
	print("hashport.py <input dir> <output dir>")
	exit()

inputDir = sys.argv[1].replace(".","").replace("\\","").replace("/","")
outputDir = sys.argv[2].replace(".","").replace("\\","").replace("/","")

if not os.path.exists(outputDir):
	os.system("mkdir \"" + outputDir + "\"")

with open("hash_list.txt", "r") as f:
	for line in f.readlines():		
		line = line.strip()
		hashList[line[:16]] = line[22:]

for root, dirs, files in os.walk(inputDir):
	dirs.sort()
	files.sort()
	for file in files:
		if file.startswith("00") and file.endswith(".meta") and os.path.exists(root + "/" + file[:-5]):
			oldHash = file[:file.find(".")]
			newHash = getNewHash()
			#print(newHash)
			hashData.append([oldHash, newHash, root + "/" + file, FileType.META])
			hashMap[hex(int(oldHash, 16))] = hex(int(newHash, 16))
			#print(oldHash, "to", newHash)
		elif file.startswith("00") and file.endswith(".entity.json"):
			oldHash = file[:file.find(".")]
			newHash = oldHash
			#newHash = getNewHash()
			#print(newHash)
			hashData.append([oldHash, newHash, root + "/" + file, FileType.JSON])
			#hashMap[hex(int(oldHash, 16))] = hex(int(newHash, 16))
			#print(oldHash, "to", newHash)
		elif file.startswith("00") and not os.path.exists(root + "/" + file + ".meta"):
			oldHash = file[:file.find(".")]
			newHash = getNewHash()
			#print(newHash)
			hashData.append([oldHash, newHash, root + "/" + file, FileType.HASH])
			hashMap[hex(int(oldHash, 16))] = hex(int(newHash, 16))
			#print(oldHash, "to", newHash)

for h in hashData:
	data = 0
	with open(h[2], "rb") as f1:
		outputFile = Path(h[2].replace(inputDir, outputDir, 1).replace(h[0], h[1]))
		if not os.path.exists(outputFile.parent):
			os.system("mkdir \"" + str(outputFile.parent) + "\"")
		if h[3] == FileType.META:
			with open(outputFile, "wb") as f2:
				data = bytearray(f1.read())
				#print(hex(struct.unpack('<q', data[0:8])[0]))
				data[0:8] = struct.pack("q", int(h[1], 16))
				#print(hex(struct.unpack('<q', data[0:8])[0]))
				dependsLength = struct.unpack('<I', data[0x18:0x1C])[0]
				if dependsLength > 0:
					dependsCount = struct.unpack('<I', data[0x2C:0x30])[0]
					#print(dependsCount)
					dependsCount -= 3221225472
					#print(dependsCount)
					offset = 0x30 + dependsCount
					for d in range(dependsCount):
						depend = hex(struct.unpack('<Q', data[offset+0:offset+8])[0])
						#print("Depend:", d, depend)
						if depend in hashMap:
							#print(depend, "in hashMap")
							#print(depend, "to", hashMap[depend])
							data[offset+0:offset+8] = struct.pack("Q", int(hashMap[depend], 16))
						offset += 8
				f2.write(data)				
			with open(str(h[2])[:-5], "rb") as f2:
				with open(str(outputFile)[:-5], "wb") as f3:
					data = bytearray(f2.read())
					f3.write(data)
		if h[3] == FileType.HASH:
			with open(outputFile, "wb") as f2:
				data = bytearray(f1.read())
				f2.write(data)
		if h[3] == FileType.JSON:
			print(outputFile)
			with open(outputFile, "w", encoding="utf-8") as f2:
				entityJSON = json.load(f1)
				#entityJSON["tempHash"] = h[1]
				#entityJSON["tbluHash"] = getNewHash()
				for entity in entityJSON["entities"]:
					ioiHash = hex(int(CalculateIOIHash(entityJSON["entities"][entity]["template"]), 16))
					if ioiHash in hashMap:
						print("Changing", entityJSON["entities"][entity]["template"], "->", ioiHash, "to", hashMap[ioiHash])
						entityJSON["entities"][entity]["template"] = str(hashMap[ioiHash][2:].upper().zfill(16))
					ioiHash = hex(int(CalculateIOIHash(entityJSON["entities"][entity]["blueprint"]), 16))
					if ioiHash in hashMap:
						print("Changing", entityJSON["entities"][entity]["blueprint"], "->", ioiHash, "to", hashMap[ioiHash])
						entityJSON["entities"][entity]["blueprint"] = str(hashMap[ioiHash][2:].upper().zfill(16))
				json.dump(entityJSON, f2, indent=4)