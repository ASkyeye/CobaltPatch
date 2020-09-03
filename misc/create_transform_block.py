#!/usr/bin/env python3
# -*- coding:utf-8 -*-
import sys
import binascii

def CreateTransformBlock( bufx64, bufx86 ):
    try:
        c64 = [bufx64[i:i+8] for i in range(0, len(bufx64), 8)]
        c86 = [bufx86[i:i+8] for i in range(0, len(bufx86), 8)]

        x64 = "transform-x64 {\n"
        x86 = "transform-x86 {\n"

        x64 += "\t# Size: 0x%x\n" % ( int(len(bufx64) / int(2)) )
        x86 += "\t# Size: 0x%x\n" % ( int(len(bufx86) / int(2)) )

        for asm in c64:
            s64 = [asm[i:i+2] for i in range(0, len(asm), 2)]

            b64 = "";
            for tmp in s64:
                b64 += "\\x%s" % str(tmp)[2:-1];

            x64 += "\tprepend \"%s\"\n" % str(b64);

        for asm in c86:
            s86 = [asm[i:i+2] for i in range(0, len(asm), 2)]
            
            b86 = "";
            for tmp in s86:
                b86 += "\\x%s" % str(tmp)[2:-1];

            x86 += "\tprepend \"%s\"\n" % str(b86);

        x64 += "}";
        x86 += "}";

        return x64, x86
    except Exception as e:
        print(e);
        raise SystemExit


def EntryPoint(argv):
    try:
        sx64 = open(argv[1], 'rb+');
        sx86 = open(argv[2], 'rb+');

        hx64 = binascii.hexlify(sx64.read());
        hx86 = binascii.hexlify(sx86.read());

        px64, px86 = CreateTransformBlock( hx64, hx86 );

        print(px64);
        print(px86);

        sx64.close()
        sx86.close()
    except Exception as e:
        print(e);
        raise SystemExit;

if __name__ in '__main__':
    if ( len(sys.argv) < 3 ):
        print("usage: %s [/path/to/bin.x64.bin] [/path/to/bin.x86.bin]" % sys.argv[0]);
    else: 
        EntryPoint(sys.argv);
