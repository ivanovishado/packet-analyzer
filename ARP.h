#ifndef ARP_H_INCLUDED
#define ARP_H_INCLUDED

#include <cstdint>
#include <cstring>
#include <arpa/inet.h>
#include <cstdio>
#include "Util.h"
#include "defs.h"

class ARP{
  uint16_t        hardwareType;
  uint16_t        protocolType;
  unsigned char   hardwareLength;
  unsigned char   protocolLength;
  uint16_t        operation;
  unsigned char   senderHardwareAddress[6];
  char            senderProtocolAddress[INET_ADDRSTRLEN+1];
  unsigned char   targetHardwareAddress[6];
  char            targetProtocolAddress[INET_ADDRSTRLEN+1];
public:
  ARP(const unsigned char* paquete);
  void imprime();
};

#endif // ARP_H_INCLUDED
