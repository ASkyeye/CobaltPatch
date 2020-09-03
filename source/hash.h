
#ifndef HASH_H
#define HASH_H

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
ULONG HashString( IN PVOID Inp, IN ULONG Len );

#endif // END HASH_H
