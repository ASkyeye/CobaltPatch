# About

Custom project template for creating useable bytecode blobs that
can be placed in the various `transform-x64` and `transform-x86`
blocks for post-ex and stage libraries.

The entrypoint of our code is stored under source/main.c EntryPoint
function. While this is not the _true_ entrypoint, it is called 
after the stack has been cleaned ( x86/x64 ) and aligned ( x64 ).

# Build

To build the template, you must install `make`, `nasm`, `mingw-w64`, 
`python3` and `pefile` from pip. Once this has completed, you must
run the `make` build command, which will produce an output similiar
to the below:

```
$ make
nasm -f win32 source/asm/EntryPointSc.asm -o EntryPointSc.x86.o
nasm -f win64 source/asm/EntryPointSc.asm -o EntryPointSc.x64.o
i686-w64-mingw32-gcc source/*.c EntryPointSc.x86.o -o patch.x86.exe -ffunction-sections -Os -fno-asynchronous-unwind-tables  -nostdlib -fno-ident -fno-align-functions -falign-functions=1 -fpack-struct=8 -Wl,-s,--no-seh,--enable-stdcall-fixup,-Tmisc/link_x86.ld
x86_64-w64-mingw32-gcc source/*.c EntryPointSc.x64.o -o patch.x64.exe -ffunction-sections -Os -fno-asynchronous-unwind-tables  -nostdlib -fno-ident -fno-align-functions -falign-functions=1 -fpack-struct=8 -Wl,-s,--no-seh,--enable-stdcall-fixup,-Tmisc/link_x64.ld
python3 misc/pedump.py patch.x86.exe patch.x86.bin
python3 misc/pedump.py patch.x64.exe patch.x64.bin
```
