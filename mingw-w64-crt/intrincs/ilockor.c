#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

LONG InterlockedOr(LONG volatile *Destination,LONG Value)
{
  __asm__ __volatile__("lock ; orl %0,%1"
    : : "r"(Value),"m"(*Destination) : "memory");
  return *Destination;
}

