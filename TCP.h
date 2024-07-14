#ifndef TCP_H_INCLUDED
#define TCP_H_INCLUDED

#include <cstdint>
#include <arpa/inet.h>
#include <cstring>
#include <bitset>
#include "Util.h"

class TCP{
  uint16_t        sourcePort;
  uint16_t        destinationPort;
  uint32_t        sequenceNumber;
  uint32_t        acknowledgmentNumber;
  unsigned char   dataOffset_Reserved_NS;
  unsigned char   moreFlags;
  uint16_t        windowSize;
  uint16_t        checksum;
  uint16_t        urgentPointer;
public:
  TCP(const u_char* paquete, int inicio);
  void      imprime();
};

#endif // TCP_H_INCLUDED
