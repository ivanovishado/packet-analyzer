#include "Ethernet.h"
#include "ARP.h"
#include "Ipv4.h"
#include "Util.h"
#include "Icmpv4.h"
#include "Ipv6.h"
#include "Icmpv6.h"
#include "UDP.h"
#include "TCP.h"
#include "DNS.h"
#include "DHCP.h"
#include "HTTP.h"
#include <pcap.h>
#include <iostream>

void llego_pkt(u_char* user, const struct pcap_pkthdr* header, const u_char* buffer);
void hacerAnalisis(int headerLength, const u_char* buffer);

int main(){
  char                  errbuf[PCAP_ERRBUF_SIZE];
  char*                 dev;
  const u_char*         buffer;
  pcap_t*               sesion;
  struct  pcap_pkthdr   header;
  dev = pcap_lookupdev(errbuf);
  if(dev == NULL){
    fprintf(stderr, "No se pudo encontrar un dispositivo por defecto: %s\n", errbuf);
    return EXIT_FAILURE;
  }
  sesion = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if(sesion == NULL){
    fprintf(stderr, "No se pudo abrir el dispositivo %s\n", errbuf);
    return EXIT_FAILURE;
  }
  if(pcap_datalink(sesion) != DLT_EN10MB){
    fprintf(stderr, "El dispositivo %s no provee cabeceras Ethernet - no soportado\n", dev);
    return EXIT_FAILURE;
  }
  //buffer = pcap_next(sesion, &header);

  //hacerAnalisis(header.len, buffer);

  pcap_loop(sesion, 10, llego_pkt, NULL);

  pcap_close(sesion);

//  FILE* archivo;
//  char nombreArchivo[40];
//  int tamanioArchivo;
//  unsigned char* buffer;
//  printf("Dame nombre de archivo: ");
//  scanf("%s", nombreArchivo);
//  archivo = fopen(strcat(nombreArchivo, ".bin"), "rb");
//  if(!archivo){
//    perror("Ha ocurrido este error");
//    return EXIT_FAILURE;
//  }
//  fseek(archivo, 0, SEEK_END);
//  tamanioArchivo = ftell(archivo);
//  rewind(archivo);
//  buffer = new unsigned char[tamanioArchivo + 1];
//  fread(buffer, 1, tamanioArchivo, archivo);
//  buffer[++tamanioArchivo] = '\0';
//  fclose(archivo);
  return EXIT_SUCCESS;
}

void llego_pkt(u_char* user, const struct pcap_pkthdr* header, const u_char* buffer){
  hacerAnalisis(header->len, buffer);
}

void hacerAnalisis(int headerLength, const u_char* buffer){
  printf("\n--- Ethernet ---\n");
  Ethernet ethernet(buffer, headerLength);
  ethernet.imprime();
  switch(ethernet.dameEthertype()){
    case 0x0806:{
      printf("\n--- ARP ---\n");
      ARP arp(buffer);
      arp.imprime();
      break;
    }
    case 0x0800:{
      printf("\n--- IPv4 ---\n");
      Ipv4 ipv4(buffer, headerLength);
      ipv4.imprime();
      switch (ipv4.dameProtocolo()){
        case 1:{
          printf("\n--- ICMPv4 ---\n");
          Icmpv4 icmpv4(buffer);
          icmpv4.imprime();
          break;
        }
        case 6:{
          printf("\n--- TCP ---\n");
          TCP tcp(buffer, 34);
          tcp.imprime();
          break;
        }
        case 17:{
          printf("\n--- UDP ---\n");
          UDP udp(buffer, 34);
          udp.imprime();
          if(udp.dameSourcePort() == 67 || udp.dameDestinationPort() == 67){
            printf("--- DHCP ---\n");
            DHCP dhcp(buffer, 42);
            dhcp.imprime();
          }else
            printf("Puerto UDP no incluido . . .\n");
          break;
        }
        default: printf("Protocolo IP no incluido . . .\n");
      }
      break;
    }
    case 0x86DD:{
      printf("\n--- IPv6 ---\n");
      Ipv6 ipv6(buffer);
      ipv6.imprime();
      switch (ipv6.dameNextHeader()){
        case 1:{
          printf("\n--- ICMPv6 ---\n");
          Icmpv6 icmpv6(buffer);
          icmpv6.imprime();
          break;
        }
        case 6:{
          printf("\n--- TCP ---\n");
          TCP tcp(buffer, 54);
          tcp.imprime();
          break;
        }
        case 17:{
          printf("\n--- UDP ---\n");
          UDP udp(buffer, 54);
          udp.imprime();
          if(udp.dameSourcePort() == 67 || udp.dameDestinationPort() == 67){
            printf("--- DHCP ---\n");
            DHCP dhcp(buffer, 62);
            dhcp.imprime();
          }else
            printf("Puerto UDP no incluido . . .\n");
          break;
        }
        default: printf("Next header no incluido . . .\n");
      }
      break;
    }
    default:  printf("Ethertype no encontrado . . .\n");
  }
}
