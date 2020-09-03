#
# Builds the shellcode for AMD64/x86.
# 

CC_X64 := x86_64-w64-mingw32-gcc
CC_X86 := i686-w64-mingw32-gcc
LINK64 := misc/link_x64.ld
LINK32 := misc/link_x86.ld
OUTX64 := patch.x64.exe
OUTX86 := patch.x86.exe
EXTX64 := EntryPointSc.x64.o
EXTX86 := EntryPointSc.x86.o
BINX64 := patch.x64.bin
BINX86 := patch.x86.bin

SOURCE := source/*.c
EXTASM := source/asm/EntryPointSc.asm
CFLAGS := -ffunction-sections -Os -fno-asynchronous-unwind-tables 
CFLAGS := $(CFLAGS) -nostdlib -fno-ident -fno-align-functions
CFLAGS := $(CFLAGS) -falign-functions=1 -fpack-struct=8
LFLAGS := -Wl,-s,--no-seh,--enable-stdcall-fixup


all: $(EXTX86) $(EXTX64) $(OUTX86) $(OUTX64) $(BINX86) $(BINX64)
	python3 misc/create_transform_block.py $(BINX64) $(BINX86)

clean:
	rm -rf $(OUTX64) $(OUTX86)
	rm -rf $(EXTX64) $(EXTX86)
	rm -rf $(BINX64) $(BINX86)


#
# x86 BIN
#
$(BINX86):
	python3 misc/pedump.py $(OUTX86) $@

#
# x86 OBJ
#
$(EXTX86):
	nasm -f win32 $(EXTASM) -o $@

#
# x86 EXE
#
$(OUTX86):
	$(CC_X86) $(SOURCE) $(EXTX86) -o $@ $(CFLAGS) $(LFLAGS),-T$(LINK32)

#
# x64 BIN
#
$(BINX64):
	python3 misc/pedump.py $(OUTX64) $@

#
# x64 OBJ
#
$(EXTX64):
	nasm -f win64 $(EXTASM) -o $@

#
# x64 EXE
#
$(OUTX64):
	$(CC_X64) $(SOURCE) $(EXTX64) -o $@ $(CFLAGS) $(LFLAGS),-T$(LINK64)
