#ifndef IPV4_INCLUDED
#define IPV4_INCLUDED

#include <cstdio>
#include <cstring>
#include <bitset>
#include <cstdint>
#include <arpa/inet.h>
#include "Util.h"

class Ipv4{
  unsigned char version_ihl;
  unsigned char dscp_ecn;
  uint16_t      totalLength;
  uint16_t      identification;
  uint16_t      flags_fragmentOffset;
  unsigned char ttl;
  unsigned char protocol;
  uint16_t      headerChecksum;
  unsigned char direccionOrigen[4];
  unsigned char direccionDestino[4];
  int           tamanioExtraHeader;
public:
  Ipv4(const unsigned char* paquete, int tamanio);
  void imprime();
  unsigned char dameProtocolo(){
    return protocol;
  }
};

#endif // IPV4_INCLUDED
