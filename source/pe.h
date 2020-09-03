
#ifndef PE_H
#define PE_H

/*
 *
 * \brief	Parses the export address table of
 * 		the provided portable executable to
 * 		locate an exported function string
 * 		matching the one requested.
 *
 * \args	PVOID Ptr : Pointer to the image's base.
 * \args	ULONG Hsh : FNV321A hash of the function string.
 *
 * \ret		SUCCESS: Pointer to the function if found.
 * \ret		FAILURE: NULL.
 *
 */
PVOID PeGetFuncEat( IN PVOID Ptr, IN ULONG Hsh );

#endif // END PE_H
