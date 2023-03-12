import struct
import sys

filename = '0017416135CF879C.BORG'

if len(sys.argv) > 1:
    filename = sys.argv[1]

with open(filename, 'rb') as f:
    boneInfoOffset = struct.unpack('<I', f.read(4))[0]
    f.seek(boneInfoOffset)

    deformBoneCount = struct.unpack('<I', f.read(4))[0]
    animatedBoneCount = struct.unpack('<I', f.read(4))[0]
    boneDefinitionOffset = struct.unpack('<I', f.read(4))[0]
    bindPoseDataOffset = struct.unpack('<I', f.read(4))[0]
    objectSpaceToBindPoseSpaceDataOffset = struct.unpack('<I', f.read(4))[0]
    boneConstraintsOffset = struct.unpack('<I', f.read(4))[0]
    poseBoneHeaderOffset = struct.unpack('<I', f.read(4))[0]

    f.seek(boneDefinitionOffset)

    for i in range(deformBoneCount):
        centerX, centerY, centerZ = struct.unpack('<fff', f.read(12))
        prevBone = struct.unpack('<I', f.read(4))[0]
        sizeX, sizeY, sizeZ = struct.unpack('<fff', f.read(12))
        name = f.read(34).split(b'\x00', 1)[0].decode('utf-8')
        bodyPart = struct.unpack('<H', f.read(2))[0]

        print(f"Bone[{i}] = {name}, bodyPart = {bodyPart}, prevBone = {prevBone}, center = {centerX}, {centerY}, {centerZ}, size = {sizeX}, {sizeY}, {sizeZ}")