#include "ARP.h"

const char* operationCodes[] = {"reserved.",
                                "Request.",
                                "Reply.",
                                "Request Reverse.",
                                "Reply Reverse.",
                                "DRARP Request.",
                                "DRARP Reply.",
                                "DRARP Error.",
                                "InARP Request.",
                                "InARP Reply.",
                                "ARP NAK.",
                                "MARS Request.",
                                "MARS Multi.",
                                "MARS MServ.",
                                "MARS Join.",
                                "MARS Leave.",
                                "MARS NAK.",
                                "MARS Unserv.",
                                "MARS SJoin.",
                                "MARS SLeave.",
                                "MARS Grouplist Request.",
                                "MARS Grouplist Reply.",
                                "MARS Redirect Map.",
                                "MAPOS UNARP.",
                                "OP_EXP1.",
                                "OP_EXP2."
};

const char* hardwareTypes[] = {"Reserved",
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

ARP::ARP(const unsigned char* paquete){
  memcpy(&hardwareType, &(paquete[14]), 2);
  hardwareType = ntohs(hardwareType);
  memcpy(&protocolType, &(paquete[16]), 2);
  protocolType = ntohs(protocolType);
  hardwareLength = paquete[18];
  protocolLength = paquete[19];
  memcpy(&operation, &(paquete[20]), 2);
  operation = ntohs(operation);
  memcpy(senderHardwareAddress, &(paquete[22]), 6);
  memcpy(senderProtocolAddress, &(paquete[28]), 4);
  inet_ntop(AF_INET, senderProtocolAddress, senderProtocolAddress, INET_ADDRSTRLEN);
  memcpy(targetHardwareAddress, &(paquete[32]), 6);
  memcpy(targetProtocolAddress, &(paquete[38]), 4);
  inet_ntop(AF_INET, targetProtocolAddress, targetProtocolAddress, INET_ADDRSTRLEN);
}

void ARP::imprime(){
  printf("Hardware Type:\t\t\t0x%04X (%s)\n", hardwareType, hardwareTypes[hardwareType]);
  printf("Protocol Type:\t\t\t0x%04X\n", protocolType);
  printf("Hardware length:\t\t%d\n", hardwareLength);
  printf("Protocol length:\t\t%d\n", protocolLength);
  printf("Operation Code:\t\t\t%d (%s)\n", operation, operationCodes[operation]);
  printf("Sender Hardware Address:\t");
  imprimeDireccionMAC(senderHardwareAddress);
  printf("\nSender IP Address:\t\t%s\n", senderProtocolAddress);
  printf("Target Hardware's Address:\t");
  imprimeDireccionMAC(targetHardwareAddress);
  printf("\nTarget's IP Address:\t\t%s\n", targetProtocolAddress);
  printf("\nResumen:\n");
  printf("Quien tiene la IP %s? Pregunta la IP %s.\n", targetProtocolAddress, senderProtocolAddress);
  printf("La IP %s esta en la direccion ", targetProtocolAddress);
  imprimeDireccionMAC(targetHardwareAddress);
  printf("\n");
}
