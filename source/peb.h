
#ifndef PEB_H
#define PEB_H

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
PVOID PebGetModule( IN ULONG Hsh );

#endif // END PEB_H
