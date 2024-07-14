#include "Icmpv4.h"

const char* icmpv4_tipos[] = {
	"Echo Reply",
	"Reserved",
	"Reserved",
	"Destination unreachale",
	"Source Quench (deprecated)",
	"Redirect message",
	"Alternate Host Address (deprecated)",
	"Reservado",
	"Echo Request",
	"Router advertisement",
	"Router solicitation",
	"Time exceeded",
	"Parameter Problem: Bad IP header",
	"Timestamp",
	"Timestamp reply",
	"Information request (deprecated)",
	"Information reply (deprecated)",
	"Address mask request (deprecated)",
	"Address mask reply (deprecated)",
	"Reserved", // Reserved for security
	"Reserved", // Reserved for robustness experiment
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Tracerout (deprecated)",
	"(deprecated)",
	"(deprecated)",
	"(deprecated)",
	"(deprecated)",
	"(deprecated)",
	"(deprecated)",
	"(deprecated)",
	"(deprecated)",
	"(deprecated)",
	"Desconocido",
	"Experimental",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Experimental",
	"Experimental",
	"Reserved"
};

const char* icmpv4_cod(int tipo, int cod){
	switch(tipo){
		case 0: return "Echo reply (used to ping)";
		case 3:
			switch(cod){
				case 0: return "Destination network unreachable";
				case 1: return "Destination host unreachable";
				case 2: return "Destination protocol unreachable";
				case 3: return "Destination port unreachable";
				case 4: return "Fragmentation required, and DF flag set";
				case 5: return "Source route failed";
				case 6: return "Destination network unknown";
				case 7: return "Destination host unknown";
				case 8: return "Source host isolated";
				case 9: return "Network administratively prohibited";
				case 10: return "Host administratively prohibited";
				case 11: return "Network unreachable for TOS";
				case 12: return "Host unreachable for TOS";
				case 13: return "Communication administratively prohibited";
				case 14: return "Host Precedence Violation";
				case 15: return "Precedence cutoff in effect";
				default: return "Codigo invalido";
			}
		case 4: return "Source quench (congestion control)";
		case 5:
			switch(cod){
				case 0: return "Redirect Datagram for the Network";
				case 1: return "Redirect Datagram for the Host";
				case 2: return "Redirect Datagram for the TOS & network";
				case 3: return "Redirect Datagram for the TOS & host";
				default: return "Codigo invalido";
			}
		case 6: return "Alternate Host Address";
		case 7: return "Reserved";
		case 8: return "Echo request (used to ping)";
		case 9: return "Router Advertisement";
		case 10: return "Router discovery/selection/solicitation";
		case 11:
			switch(cod){
				case 0: return "TTL expired in transit";
				case 1: return "Fragment reassembly time exceeded";
				default: return "Codigo invalido";
			}
		case 12:
			switch(cod){
				case 0: return "Pointer indicates the error";
				case 1: return "Missing a required option";
				case 2: return "Bad length";
				default: return "Codigo invalido";
			}
		case 13: return "Timestamp";
		case 14: return "Timestamp reply";
		case 15: return "Information request";
		case 16: return "Information reply";
		case 17: return "Address mask request";
		case 18: return "Address mask reply";
		case 19: return "Reserved for security";
		case 30: return "Information Request";
		case 31: return "Datagram Conversion Error";
		case 32: return "Mobile Host Redirect";
		case 33: return "Where-Are-You (originally meant for IPv6)";
		case 34: return "Here-I-Am (originally meant for IPv6)";
		case 35: return "Mobile Registration Request";
		case 36: return "Mobile Registration Reply";
		case 37: return "Domain Name Request";
		case 38: return "Domain Name Reply";
		case 39: return "SKIP Algorithm Discovery Protocol, Simple Key-Management for Internet Protocol";
		case 40: return "Photuris, Security failures";
		case 41: return "ICMP for experimental mobility protocols such as Seamoby [RFC4065]";
		case 253: return "RFC3692-style Experiment 1 (RFC 4727)";
		case 254: return "RFC3692-style Experiment 2 (RFC 4727)";
		case 255: return "Reserved";
		default: return "tipo invalido";
	}
}

Icmpv4::Icmpv4(const unsigned char* paquete){
  tipo    =   paquete[34];
  codigo  =   paquete[35];
  memcpy(&checksum, &(paquete[36]), 2);
  checksum = ntohs(checksum);
}

void Icmpv4::imprime(){
  printf("Tipo:\t\t\t%d (%s)\n", tipo, icmpv4_tipos[tipo]);
  printf("Codigo:\t\t\t%d (%s)\n", codigo, icmpv4_cod(tipo, codigo));
  printf("Checksum:\t\t0x%02X\n", checksum);
}
