;;
;;	Calculates the current position in memory
;;	of our shellcode, and passes it to our 
;;	C entrypoint.
;;

global LeavePointSc
global EntryPointSc

segment .text

EntryPointSc:
	%ifidn __OUTPUT_FORMAT__, win32
		incbin "source/asm/get_pos.x86.bin"
		push ebp
		mov ebp, esp
	%else
		incbin "source/asm/get_pos.x64.bin"
		push rsi
		mov rsi, rsp
		and rsp, 0FFFFFFFFFFFFFFF0h
		sub rsp, 020h
	%endif

	%ifidn __OUTPUT_FORMAT__, win32
		extern _EntryPoint
		; EntryPoint( eax );
		push eax
		call _EntryPoint
		leave;
	%else
		extern EntryPoint
		; EntryPoint( rcx );
		call EntryPoint
		mov rsp, rsi;
		pop rsi;
	%endif

	jmp LeavePointSc

segment .text$B

LeavePointSc:
	int3
	int3
	int3
	int3
