#include "Icmpv6.h"

const char* icmpv6_tipos[] = {
    "Reserved",
    "Destination Unreachable",
    "Packet Too Big",
    "Time Exceeded",
    "Parameter Problem",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "Private experimentation",
    "Private experimentation",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Unassigned",
    "Reserved for expansion of ICMPv6 error messages",
    "Echo Request",
    "Echo Reply",
    "Multicast Listener Query",
    "Multicast Listener Report",
    "Multicast Listener Done",
    "Router Solicitation (NDP)",
    "Router Advertisement (NDP)",
    "Neighbor Solicitation (NDP)",
    "Neighbor Advertisement (NDP)",
    "Redirect Message (NDP)",
    "Router Renumbering",
    "ICMP Node Information Query",
    "ICMP Node Information Response",
    "Inverse Neighbor Discovery Solicitation Message",
    "Inverse Neighbor Discovery Advertisement Message",
    "Multicast Listener Discovery (MLDv2) reports (RFC 3810)",
    "Home Agent Address Discovery Request Message",
    "Home Agent Address Discovery Reply Message",
    "Mobile Prefix Solicitation",
    "Mobile Prefix Advertisement",
    "Certification Path Solicitation (SEND)",
    "Certification Path Advertisement (SEND)",
    "Multicast Router Advertisement (MRD)",
    "Multicast Router Solicitation (MRD)",
    "Multicast Router Termination (MRD)",
    "no existente",
    "RPL Control Message",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "Private experimentation",
    "Private experimentation",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "no existente",
    "Reserved for expansion of ICMPv6 informational messages"
};

const char* icmpv6_cod(int tipo, int cod){
    switch(tipo){
    case 1:
        switch(cod){
        case 0: return "no route to destination";
        case 1: return "communication with destination administratively prohibited";
        case 2: return "beyond scope of source address";
        case 3: return "address unreachable";
        case 4: return "port unreachable";
        case 5: return "source address failed ingress/egress policy";
        case 6: return "reject route to destination";
        case 7: return "Error in Source Routing Header";
        default: return "Invalido";
        }
    case 3:
        switch(cod){
        case 0: return "hop limit exceeded in transit";
        case 1: return "fragment reassembly time exceeded";
        default: return "Invalido";
        }
    case 4:
        switch(cod){
        case 0: return "erroneous header field encountered";
        case 1: return "unrecognized Next Header type encountered";
        case 2: return "unrecognized IPv6 option encountered";
        default: return "Invalido";
        }
    case 138:
        switch(cod){
        case 0: return "Router Renumbering Command";
        case 1: return "Router Renumbering Result";
        case 255: return "Sequence Number Reset";
        default: return "Invalido";
        }
    case 139:
        switch(cod){
        case 0: return "The Data field contains an IPv6 address which is the Subject of this Query.";
        case 1: return "The Data field contains a name which is the Subject of this Query, or is empty, as in the case of a NOOP.";
        case 2: return "The Data field contains an IPv4 address which is the Subject of this Query.";
        default: return "Invalido";
        }
    case 140:
        switch(cod){
        case 0: return "A successful reply. The Reply Data field may or may not be empty.";
        case 1: return "The Responder refuses to supply the answer. The Reply Data field will be empty.";
        case 2: return "The Qtype of the Query is unknown to the Responder. The Reply Data field will be empty.";
        default: return "Invalido";
        }
    default:
        return "No contiene codigo";
    }
}

Icmpv6::Icmpv6(const unsigned char* paquete){
  tipo = paquete[54];
  codigo = paquete[55];
  memcpy(&checksum, &(paquete[56]), 2);
}

void Icmpv6::imprime(){
  printf("Tipo:\t\t\t%d (%s)\n", tipo, icmpv6_tipos[tipo]);
  printf("Codigo:\t\t\t%d (%s)\n", codigo, icmpv6_cod(tipo, codigo));
  printf("Checksum:\t\t0x%02X\n", checksum);
}
