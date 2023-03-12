# This only works with old versions of the game.
# Newer versions removed the unhashed pin name strings
# and only the CRC32 remains.

from idautils import *
import binascii

def get_arg_string(addr):
    while True:
        addr = idc.PrevHead(addr)
        if GetMnem(addr) == "lea" and "rcx" in GetOpnd(addr, 0):
            return idc.GetString(GetOperandValue(addr, 1))

    return ""


def main():
    print("Hello IDA world!")
    
    strings = set()

    # Address to GetPinID
    for x in XrefsTo(0x140E2DDD0, flags=0):
        arg_string = get_arg_string(x.frm)
        
        if arg_string is not None:
            strings.add(arg_string)

    strings = sorted(strings)

    for x in strings:
        print("{ %d, \"%s\" }," % (binascii.crc32(x), x))

if __name__=='__main__':
    main()