
#include "common.h"

/*
 *
 * \brief	Enumerates the process loaded modules
 * 		list. If a module is found, it will
 * 		return a pointer to its base to be 
 * 		parsed.
 *
 * \args	32-bit hash of the modules name.
 *
 * \ret		SUCCESS: Pointer to the images base.
 * \ret		FAILURE: NULL.
 *
 */
SCFUNC PVOID PebGetModule( IN ULONG Hsh )
{
	PPEB                  peb;
	PPEB_LDR_DATA         ldr;
	PLDR_DATA_TABLE_ENTRY dte;
	PLIST_ENTRY           ent;
	PLIST_ENTRY           hdr;
	ULONG                 mod;

	peb = NtCurrentTeb()->ProcessEnvironmentBlock;
	ldr = peb->Ldr;
	hdr = & ldr->InLoadOrderModuleList;
	ent = hdr->Flink;

	for ( ; hdr != ent ; ent = ent->Flink ) {
		dte = CPTR( ent );
		mod = HashString( dte->BaseDllName.Buffer, dte->BaseDllName.Length );

		if ( mod == Hsh ) {
			return CPTR( dte->DllBase );
		};
	};
	return NULL;
};
