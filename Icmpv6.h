#ifndef ICMPV6_H_INCLUDED
#define ICMPV6_H_INCLUDED

#include <cstdint>
#include <cstring>
#include <cstdio>
#include <pcap.h>

class Icmpv6{
  unsigned char tipo;
  unsigned char codigo;
  uint16_t      checksum;
public:
  Icmpv6(const unsigned char* paquete);
  void imprime();
};

#endif // ICMPV6_H_INCLUDED
