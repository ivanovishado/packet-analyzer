#ifndef ETHERNET_H_INCLUDED
#define ETHERNET_H_INCLUDED

#include <cstdint>
#include <cstring>
#include <cstdio>
#include <map>
#include <arpa/inet.h>
#include "Util.h"

class Ethernet{
  unsigned char               macAddressDestino[6];
  uint64_t                    macDestino;
  unsigned char               macAddressOrigen[6];
  uint64_t                    macOrigen;
  uint16_t                    ethertype;
  int                         tamanioCargaUtil;
  std::map<int, std::string>  diccionario;
  void cargaEtherTypes();
  std::string determinaMetodoTransmision(uint64_t& direccion);
public:
  Ethernet(const unsigned char* paquete, int tamanio);
  void imprime();
  uint16_t dameEthertype();
};

#endif // ETHERNET_H_INCLUDED
