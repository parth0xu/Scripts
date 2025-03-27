#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>
#include <pcap/pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int link_hdr_length = 0;

void process_packet(u_char *args, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    packet += link_hdr_length;
    struct ip *ip_hdr = (struct ip *)packet;

    char src_ip[INET_ADDRSTRLEN], dst_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(ip_hdr->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_hdr->ip_dst), dst_ip, INET_ADDRSTRLEN);

    printf("\nPacket Captured: \n");
    printf("SRC: %s | DST: %s | TTL: %d | TOS: 0x%x | ID: %d\n",
           src_ip, dst_ip, ip_hdr->ip_ttl, ip_hdr->ip_tos, ntohs(ip_hdr->ip_id));

    // Detect Protocol
    switch (ip_hdr->ip_p) {
        case IPPROTO_TCP: {
            struct tcphdr *tcp_hdr = (struct tcphdr *)(packet + ip_hdr->ip_hl * 4);
            printf("Protocol: TCP | SRC Port: %d | DST Port: %d\n",
                   ntohs(tcp_hdr->th_sport), ntohs(tcp_hdr->th_dport));
            break;
        }
        case IPPROTO_UDP: {
            struct udphdr *udp_hdr = (struct udphdr *)(packet + ip_hdr->ip_hl * 4);
            printf("Protocol: UDP | SRC Port: %d | DST Port: %d\n",
                   ntohs(udp_hdr->uh_sport), ntohs(udp_hdr->uh_dport));
            break;
        }
        case IPPROTO_ICMP: {
            struct icmphdr *icmp_hdr = (struct icmphdr *)(packet + ip_hdr->ip_hl * 4);
            printf("Protocol: ICMP | Type: %d | Code: %d\n", icmp_hdr->type, icmp_hdr->code);
            break;
        }
        default:
            printf("Protocol: Other (%d)\n", ip_hdr->ip_p);
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <network_interface>\n", argv[0]);
        return 1;
    }

    char *device = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];

    // Open the network interface for packet capture
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("ERROR: pcap_open_live() failed: %s\n", errbuf);
        return 1;
    }

    printf("Sniffing on interface: %s\n", device);

    // Determine link-layer header length
    int link_type = pcap_datalink(handle);
    switch (link_type) {
        case DLT_NULL: link_hdr_length = 4; break;
        case DLT_EN10MB: link_hdr_length = 14; break;
        default: link_hdr_length = 0;
    }

    // Capture packets (infinite loop until user stops)
    if (pcap_loop(handle, 0, process_packet, NULL) < 0) {
        printf("ERROR: pcap_loop() failed!\n");
        return 1;
    }

    pcap_close(handle);
    return 0;
}
