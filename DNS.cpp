#include "DNS.h"

const char* dnsTypes[] = {
  "A (a host address)",
  "NS (an authoritative name server)",
  "MD (a mail destination (Obsolete - use MX))",
  "MF (a mail forwarder (Obsolete - use MX))",
  "CNAME (the canonical name for an alias)",
  "SOA (marks the start of a zone of authority)",
  "MB (a mailbox domain name (EXPERIMENTAL))",
  "MG (a mail group member (EXPERIMENTAL))",
  "MR (a mail rename domain name (EXPERIMENTAL))",
  "NULL (a null RR (EXPERIMENTAL))",
  "WKS (a well known service description)",
  "PTR (a domain name pointer)",
  "HINFO (host information)",
  "MINFO (mailbox or mail list information)",
  "MX (mail exchange)",
  "TXT (16 text strings)"
};

DNS::DNS(const u_char* paquete, int inicio){
  memcpy(&transactionID,  &(paquete[inicio]),     2);
  memcpy(&flags,          &(paquete[inicio+2]),   2);
  memcpy(&questions,      &(paquete[inicio+4]),   2);
  memcpy(&answerRR,       &(paquete[inicio+6]),   2);
  memcpy(&authorityRR,    &(paquete[inicio+8]),   2);
  memcpy(&aditionalRR,    &(paquete[inicio+10]),  2);
  transactionID   =   ntohs(transactionID);
  flags           =   ntohs(flags);
  questions       =   ntohs(questions);
  answerRR        =   ntohs(answerRR);
  authorityRR     =   ntohs(authorityRR);
  aditionalRR     =   ntohs(aditionalRR);
}

void DNS::imprime(){
  std::bitset<16> qr(flags);
  printf("Transaction ID: %d", transactionID);
  printf("Flags:\n");
  printf("QR:\t\t");
  determinaBitEncendidoApagado(qr, 0);
  printf("Opcode:");
  printf("Questions:\t\t%d", questions);
  printf("Answers:\t\t%d", answerRR);
  printf("Authority:\t\t%d", authorityRR);
  printf("Aditional:\t\t%d", aditionalRR);
}
