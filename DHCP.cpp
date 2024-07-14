#include "DHCP.h"

const char* messageTypes[] = {
  "BOOTREQUEST",
  "BOOTREPLY"
};

const char* hardwareTypesDHCP[] = {
  "Reserved",
  "Ethernet (10Mb)",
  "Experimental Ethernet (3Mb)",
  "Amateur Radio AX.25",
  "Proteon ProNET Token Ring",
  "Chaos",
  "IEEE 802 Networks",
  "ARCNET",
  "Hyperchannel",
  "Lanstar",
  "Autonet Short Address",
  "LocalTalk",
  "LocalNet (IBM PCNet or SYTEK LocalNET)",
  "Ultra link",
  "SMDS",
  "Frame Relay",
  "Asynchronous Transmission Mode (ATM)",
  "HDLC",
  "Fibre Channel",
  "Asynchronous Transmission Mode (ATM)",
  "Serial Line",
  "Asynchronous Transmission Mode (ATM)",
  "MIL-STD-188-220",
  "Metricom",
  "IEEE 1394.1995",
  "MAPOS",
  "Twinaxial",
  "EUI-64",
  "HIPARP",
  "IP and ARP over ISO 7816-3",
  "ARPSec",
  "IPsec tunnel",
  "InfiniBand (TM)",
  "TIA-102 Project 25 Common Air Interface (CAI)",
  "Wiegand Interface",
  "Pure IP",
  "HW_EXP1",
  "HFI",
  "Unassigned",
  "HW_EXP2",
  "Unassigned",
  "Reserved"
};

DHCP::DHCP(const u_char* paquete, int inicio){
  messageType         =   paquete[inicio];
  hardwareType        =   paquete[inicio+1];
  hardwareAddressLen  =   paquete[inicio+2];
  hops                =   paquete[inicio+3];
  memcpy(&transactionID,    &(paquete[inicio+4]),   4);
  memcpy(&secondsElapsed,   &(paquete[inicio+8]),   2);
  memcpy(&flags,            &(paquete[inicio+10]),  2);
  memcpy(&clientAddress,    &(paquete[inicio+12]),  4);
  memcpy(&yourAddress,      &(paquete[inicio+16]),  4);
  memcpy(&nextServerIP,     &(paquete[inicio+20]),  4);
  memcpy(&relayAgentIP,     &(paquete[inicio+24]),  4);
  memcpy(clientMacAddress, &(paquete[inicio+28]),  6);
  memcpy(serverHostName,   &(paquete[inicio+44]),  64);
  memcpy(bootFile,         &(paquete[inicio+108]), 128);
  memcpy(&magicCookie,      &(paquete[inicio+236]), 4);
  memcpy(options,          &(paquete[inicio+240]), 60);
  inet_ntop(AF_INET, clientAddress, clientAddress, INET_ADDRSTRLEN);
  inet_ntop(AF_INET, yourAddress, yourAddress, INET_ADDRSTRLEN);
  inet_ntop(AF_INET, nextServerIP, nextServerIP, INET_ADDRSTRLEN);
  inet_ntop(AF_INET, relayAgentIP, relayAgentIP, INET_ADDRSTRLEN);
  transactionID   =   ntohl(transactionID);
  secondsElapsed  =   ntohs(secondsElapsed);
  flags           =   ntohs(flags);
  magicCookie     =   ntohl(magicCookie);
}

void DHCP::imprime(){
  std::bitset<16> broadcastFlag(flags);
  uint16_t minutos, horas;
  minutos = secondsElapsed / 60;
  horas = minutos / 60;
  printf("Message Type:\t\t%d (%s)\n", messageType, messageTypes[messageType-1]);
  printf("Hardware Type:\t\t%d (%s)\n", hardwareType, hardwareTypesDHCP[hardwareType]);
  printf("Hardware Address Length:\t\t%d\n", hardwareAddressLen);
  printf("Hops:\t\t%d\n", hops);
  printf("Transaction ID:\t\t%d\n", transactionID);
  printf("Seconds Elapsed:\t\t%d:%d:%d\n", int(horas), int(minutos%60), int(secondsElapsed%60));
  printf("Broadcast flag:\t\t");
  determinaBitEncendidoApagado(broadcastFlag, 15);
  printf("Client Address:\t\t%s\n", clientAddress);
  printf("Your (client) Address:\t\t%s\n", yourAddress);
  printf("Next Server IP:\t\t%s\n", nextServerIP);
  printf("Relay Agent IP:\t\t%s\n", relayAgentIP);
  printf("Client MAC Address:\t");
  imprimeDireccionMAC(clientMacAddress);
  printf("Server Host Name:\t\t%s\n", serverHostName);
  printf("Boot file name:\t\t%s\n", bootFile);
  printf("Magic Cookie:\t\t0x%08X\n", magicCookie);
  ///Options
}
