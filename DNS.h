#ifndef DNS_H_INCLUDED
#define DNS_H_INCLUDED

#include <cstdint>
#include <cstring>
#include <arpa/inet.h>
#include <bitset>
#include "Util.h"

class DNS{
  uint16_t  transactionID;
  uint16_t  flags;
  uint16_t  questions;
  uint16_t  answerRR;
  uint16_t  authorityRR;
  uint16_t  aditionalRR;
public:
  DNS(const u_char* paquete, int inicio);
  void imprime();
};

#endif // DNS_H_INCLUDED
