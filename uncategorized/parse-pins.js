// This script reads entity pins from pins.txt, in the format
// that 2kprs script dumped them in, and dumps them out as JSON.
const fs = require('fs');
const crypto = require('crypto');

const lines = fs.readFileSync('pins.txt', 'utf8').split('\n');

const pins = {};

const allInputPins = new Set();
const allOutputPins = new Set();

const inputPins = new Set();
const outputPins = new Set();

let currentEntity = null;
let currentEntityHash = null;
let input = true;

for (const line of lines) {
    if (line === 'Input pins:') {
        input = true;
    } else if (line === 'Output pins:') {
        input = false;
    } else if (line.startsWith('  - ')) {
        const pinName = line.substring('  - '.length);

        if (input) {
            inputPins.add(pinName);
            allInputPins.add(pinName);
        } else {
            outputPins.add(pinName);
            allOutputPins.add(pinName);
        }
    } else if (line.trim().length > 0 && line.endsWith(':')) {
        if (currentEntity !== null) {
            pins[currentEntity] = {
                hash: currentEntityHash,
                in: Array.from(inputPins).sort(),
                out: Array.from(outputPins).sort(),
            };

            inputPins.clear();
            outputPins.clear();
        }

        currentEntity = line.substring(0, line.length - 1);
        currentEntityHash = currentEntity.toLowerCase();

        // If the entity name doesn't start with 00 and isnt 16 characters,
        // then it's an IOI path and we need to hash it.
        if (currentEntity.length !== 16 || !currentEntity.startsWith('00')) {
            const hash = crypto.createHash('md5');
            hash.update(currentEntity);
            const hashHex = hash.digest('hex');
            currentEntityHash = '00' + hashHex.substring(2, 16);
        }

        input = true;
    } else {
        console.log(`Unknown line = "${line}"`);
    }
}

if (currentEntity !== null) {
    pins[currentEntity] = {
        hash: currentEntityHash,
        in: Array.from(inputPins).sort(),
        out: Array.from(outputPins).sort(),
    };

    inputPins.clear();
    outputPins.clear();
}

// Sort pins object by key.
const sortedPins = {};
Object.keys(pins).sort().forEach(key => {
    sortedPins[key] = pins[key];
});

// Map to array.
const pinsArray = [];

for (const entity in sortedPins) {
    const entityPinData = sortedPins[entity];

    pinsArray.push({
        hash: entityPinData.hash,
        path: entity,
        in: entityPinData.in,
        out: entityPinData.out,
    });
}

console.log(JSON.stringify(pinsArray, null, 4));

//console.log('All input pins:');
//console.log(Array.from(allInputPins).sort().join('\n'));

//console.log('All output pins:');
//console.log(Array.from(allOutputPins).sort().join('\n'));