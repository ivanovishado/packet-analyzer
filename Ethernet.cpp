#include "Ethernet.h"

Ethernet::Ethernet(const unsigned char* paquete, int tamanio){
  cargaEtherTypes();
  memcpy(macAddressDestino, &(paquete[0]), 6);
  memcpy(&macDestino, &(paquete[0]), 6);
  memcpy(macAddressOrigen, &(paquete[6]), 6);
  memcpy(&macOrigen, &(paquete[6]), 6);
  memcpy(&ethertype, &(paquete[12]), 2);
  ethertype = ntohs(ethertype);
  tamanioCargaUtil = (tamanio - 5) - 14;
}

void Ethernet::imprime(){
  printf("MAC Destino:\t\t");
  imprimeDireccionMAC(macAddressDestino);
  printf(" %s\n", determinaMetodoTransmision(macDestino).c_str());
  printf("MAC Origen:\t\t");
  imprimeDireccionMAC(macAddressOrigen);
  printf(" %s\n", determinaMetodoTransmision(macOrigen).c_str());
  printf("Ethertype:\t\t0x%04X (%s)\n", ethertype, diccionario[ethertype].c_str());
  printf("Carga util:\t\t%d bytes.\n", tamanioCargaUtil);
}

uint16_t Ethernet::dameEthertype(){
  return ethertype;
}

void Ethernet::cargaEtherTypes(){
  diccionario[0x0800] = "Internet Protocol version 4 (IPv4)";
  diccionario[0x0806] = "Address Resolution Protocol (ARP)";
  diccionario[0x0808] = "Frame Relay ARP";
  diccionario[0x880B] = "Point-to-Point Tunneling Protocol (PPTP)";
  diccionario[0x880C] = "General Switch Management Protocol (GSMP)";
  diccionario[0x8035] = "Reverse Address Resolution Protocol (RARP)";
  diccionario[0x0842] = "Wake-on-LAN[3]";
  diccionario[0x86DD] = "Internet Protocol version 6 (IPv6)";
  diccionario[0x8847] = "MPLS";
  diccionario[0x8848] = "MPLS with upstream-assigned label";
  diccionario[0x8861] = "Multicast Channel Allocation Protocol (MCAP)";
  diccionario[0x8863] = "PPP over Ethernet (PPPoE) Discovery Stage";
  diccionario[0x8864] = "PPP over Ethernet (PPPoE) Session Stage";
}

std::string Ethernet::determinaMetodoTransmision(uint64_t& direccion){
  std::bitset<48> bits(direccion);
  if(bits.all())
    return "(Broadcast)";
  else if(bits.test(0))
    return "(Multicast)";
  else
    return "(Unicast)";
}
