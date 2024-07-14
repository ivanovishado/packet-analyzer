#ifndef DHCP_H_INCLUDED
#define DHCP_H_INCLUDED

#include <cstdint>
#include <arpa/inet.h>
#include <cstring>
#include <bitset>
#include "Util.h"

class DHCP{
  unsigned char   messageType           ;
  unsigned char   hardwareType          ;
  unsigned char   hardwareAddressLen    ;
  unsigned char   hops                  ;
  uint32_t        transactionID         ;
  uint16_t        secondsElapsed        ;
  uint16_t        flags                 ;
  char            clientAddress[INET_ADDRSTRLEN+1]      ;
  char            yourAddress[INET_ADDRSTRLEN+1]        ;
  char            nextServerIP[INET_ADDRSTRLEN+1]       ;
  char            relayAgentIP[INET_ADDRSTRLEN+1]       ;
  unsigned char   clientMacAddress[6]  ;
  unsigned char   serverHostName[64]    ;
  unsigned char   bootFile[128]         ;
  uint32_t        magicCookie           ;
  unsigned char   options[64]           ;
public:
  DHCP(const u_char* paquete, int inicio);
  void imprime();
};

#endif // DHCP_H_INCLUDED
