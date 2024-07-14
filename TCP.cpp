#include "TCP.h"

TCP::TCP(const u_char* paquete, int inicio){
  memcpy(&sourcePort, &(paquete[inicio]), 2);
  memcpy(&destinationPort, &(paquete[inicio+2]), 2);
  memcpy(&sequenceNumber, &(paquete[inicio+4]), 4);
  memcpy(&acknowledgmentNumber, &(paquete[inicio+8]), 4);
  dataOffset_Reserved_NS = paquete[inicio+12];
  moreFlags = paquete[inicio+13];
  memcpy(&windowSize, &(paquete[inicio+14]), 2);
  memcpy(&checksum, &(paquete[inicio+16]), 2);
  memcpy(&urgentPointer, &(paquete[inicio+18]), 2);
  sourcePort            =   ntohs(sourcePort);
  destinationPort       =   ntohs(destinationPort);
  sequenceNumber        =   ntohl(sequenceNumber);
  acknowledgmentNumber  =   ntohl(acknowledgmentNumber);
  windowSize            =   ntohs(windowSize);
  checksum              =   ntohs(checksum);
  urgentPointer         =   ntohs(urgentPointer);
}

void TCP::imprime(){
  unsigned char temp;
  uint8_t       dataOffsetBytes;
  std::bitset<8> ns(dataOffset_Reserved_NS);
  std::bitset<8> flags(moreFlags);
  printf("Source Port:\t\t%d\n", sourcePort);
  printf("Destination Port:\t%d\n", destinationPort);
  printf("Sequence Number:\t%d\n", sequenceNumber);
  printf("Acknowledgment Number:\t%d\n", acknowledgmentNumber);
  temp = dataOffset_Reserved_NS >> 4;
  printf("Data Offset:\t\t%d (%d bytes)\n", temp, dataOffsetBytes=(temp-5)*4);
  printf("Banderas encendidas:\n");
  printf("NS:\t\t\t");
  determinaBitEncendidoApagado(ns, 0);
  printf("CWR:\t\t\t");
  determinaBitEncendidoApagado(flags, 7);
  printf("ECE:\t\t\t");
  determinaBitEncendidoApagado(flags, 6);
  printf("URG:\t\t\t");
  determinaBitEncendidoApagado(flags, 5);
  printf("ACK:\t\t\t");
  determinaBitEncendidoApagado(flags, 4);
  printf("PSH:\t\t\t");
  determinaBitEncendidoApagado(flags, 3);
  printf("RST:\t\t\t");
  determinaBitEncendidoApagado(flags, 2);
  printf("SYN:\t\t\t");
  determinaBitEncendidoApagado(flags, 1);
  printf("FIN:\t\t\t");
  determinaBitEncendidoApagado(flags, 0);
  printf("Window Size:\t\t%d\n", windowSize);
  printf("Checksum:\t\t0x%04X\n", checksum);
  printf("Urgent Pointer:\t\t%d\n", urgentPointer);
  printf("Hay %d bytes de cabeceras extra.\n", dataOffsetBytes);
}
