#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <climits>

void imprimeDireccionIP(unsigned char* direccion);
void imprimeDireccionMAC(unsigned char* direccion);

template<long unsigned int T>
void determinaBitEncendidoApagado(std::bitset<T>& bit, int numBit){
  if(bit.test(numBit))
    printf("on");
  else
    printf("off");
  printf("\n");
}

#endif // UTIL_H_INCLUDED
