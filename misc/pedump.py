#!/usr/bin/env python3
# -*- coding:utf-8 -*-
import pefile
import sys

def EntryPoint(argv):
    try:
        if ( len(argv) < 3 ):
            print("usage: %s [/path/to/sc.exe] [/path/to/raw.bin]" % argv[0]);
            raise SystemExit;
        else:
            #
            # Locates the .text section of the pe
            # file and dumps it to a arbitrary 
            # file to disk.
            #
            fpe = pefile.PE(argv[1]);
            raw = fpe.sections[0].get_data()
            
            ofs = raw.index(b'\xcc\xcc\xcc\xcc');
            raw = raw[:ofs];

            bin = open(argv[2], 'wb+');
            bin.write(raw);
            bin.close();

    except Exception as e:
        print("error: %s" % e);

if __name__ in '__main__':
    EntryPoint(sys.argv);
