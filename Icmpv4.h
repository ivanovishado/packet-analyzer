#ifndef ICMPV4_H_INCLUDED
#define ICMPV4_H_INCLUDED

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <arpa/inet.h>

class Icmpv4{
  unsigned char tipo;
  unsigned char codigo;
  uint16_t      checksum;
public:
  Icmpv4(const unsigned char* paquete);
  void imprime();
};

#endif // ICMPV4_H_INCLUDED
