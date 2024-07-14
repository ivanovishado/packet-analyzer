#ifndef UDP_H_INCLUDED
#define UDP_H_INCLUDED

#include <cstdint>
#include <cstring>
#include <arpa/inet.h>
#include <cstdio>

class UDP{
  uint16_t sourcePort;
  uint16_t destinationPort;
  uint16_t length;
  uint16_t checksum;
public:
  UDP(const unsigned char* paquete, int inicio);
  void imprime();
  uint16_t dameDestinationPort();
  uint16_t dameSourcePort();
};

#endif // UDP_H_INCLUDED
