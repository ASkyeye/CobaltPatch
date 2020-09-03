
#include "common.h"

/*
 *
 * \brief	Creates a DJB2 hash of the incoming string.
 * 		The function is capable of converting any
 * 		unicode / ansi strings to the same hash.
 *
 * 		Credit for that portion of the function goes
 * 		to ZeroSum's ZeroLoad @ zdi/dll/zeroload/hash.h
 *
 * \args	Pointer to the input string. 
 * \args	Length of the incoming string. 0 for ANSI.
 *
 * \ret		SUCCESS: DJB2 Hash
 * \ret		FAILURE: Crash?
 *
 */
SCFUNC ULONG HashString( IN PVOID Inp, IN ULONG Len )
{
	ULONG  hsh;
	PUCHAR ptr;
	UCHAR  cur;

	hsh = 5381;
	ptr = Inp;

	while ( TRUE )
	{
		cur = * ptr;

		if ( ! Len ) {
			if ( ! * ptr ) {
				break;
			};
		} else {
			if ( ( ULONG )( ptr - ( PUCHAR )Inp ) >= Len ) {
				break;
			};
			if ( ! * ptr ) {
				++ptr; continue;
			};
		};

		if ( cur >= 'a' )
			cur -= 0x20;

		hsh = ((hsh << 5) + hsh) + cur; ++ptr;
	};

	return hsh;
};
