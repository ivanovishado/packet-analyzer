#include "Util.h"

void imprimeDireccionIP(unsigned char* direccion){
  for(int i = 0; i < 3; i++)
    printf("%03d.", direccion[i]);
  printf("%03d\n", direccion[3]);
}

void imprimeDireccionMAC(unsigned char* direccion){
  for(int i = 0; i < 5; i++)
    printf("%02X:", direccion[i]);
  printf("%02X", direccion[5]);
}
