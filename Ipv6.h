#ifndef IPV6_H_INCLUDED
#define IPV6_H_INCLUDED

#include <cstdio>
#include <cstring>
#include <cstdint>
#include <arpa/inet.h>
#include "Util.h"
class Ipv6{
  unsigned char   version_traffic_flowLabel[4];
  uint16_t        payloadLength;
  unsigned char   nextHeader;
  unsigned char   hopLimit;
  char            sourceAddress[INET6_ADDRSTRLEN+1];
  char            destinationAddress[INET6_ADDRSTRLEN+1];
public:
  Ipv6(const unsigned char* paquete);
  void imprime();
  unsigned char dameNextHeader(){
    return nextHeader;
  }
};

#endif // IPV6_H_INCLUDED
