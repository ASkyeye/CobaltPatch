
#ifndef COMMON_H
#define COMMON_H

//! External Includes
#include <windows.h>
#include <ntstatus.h>

//! Structures
#include "ntpeb.h"

//! Macros
#define SCFUNC		__attribute__((section(".text$A")))
#define PREF(x)		*((PULONG_PTR)x)
#define UPTR(x) 	((ULONG_PTR)x)
#define CPTR(x) 	((PVOID)x)
#define FUNC(x) 	__typeof__(x) * x


//! Function Table
typedef struct
{

} API;

#include "hashes.h"
#include "hash.h"
#include "peb.h"
#include "pe.h"

#endif // END COMMON_H
