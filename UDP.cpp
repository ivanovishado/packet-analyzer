#include "UDP.h"

UDP::UDP(const unsigned char* paquete, int inicio){
  memcpy(&sourcePort,       &(paquete[inicio]),   2);
  memcpy(&destinationPort,  &(paquete[inicio+2]), 2);
  memcpy(&length,           &(paquete[inicio+4]), 2);
  memcpy(&checksum,         &(paquete[inicio+6]), 2);
  sourcePort      =   ntohs(sourcePort);
  destinationPort =   ntohs(destinationPort);
  length          =   ntohs(length);
  checksum        =   ntohs(checksum);
}

void UDP::imprime(){
  printf("Source port:\t\t%d\n", sourcePort);
  printf("Destination port:\t%d\n", destinationPort);
  printf("Length:\t\t\t%d\n", length);
  printf("Checksum:\t\t0x%04X\n", checksum);
  printf("Hay %d bytes despues del checksum.\n", length);
}

uint16_t UDP::dameSourcePort(){
  return sourcePort;
}

uint16_t UDP::dameDestinationPort(){
  return destinationPort;
}
