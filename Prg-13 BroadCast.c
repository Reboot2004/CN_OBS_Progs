/*
Take an example subnet of hosts and obtain a broadcast tree for the subnet.

Enter IP address: 192.168.1.0
Enter prefix length: 24

No of subnets: 2
No of hosts per subnet: 126

Broadcast Tree:

Subnet 1:
Network Address: 192.168.1.0
Broadcast Address: 192.168.1.127
Subnet Mask: 255.255.255.128
Hosts: 192.168.1.1 192.168.1.2 ... 192.168.1.126 

Subnet 2:
Network Address: 192.168.1.128
Broadcast Address: 192.168.1.255
Subnet Mask: 255.255.255.128
Hosts: 192.168.1.129 192.168.1.130 ... 192.168.1.254 

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
unsigned int ipToInt(char *ip) {
    unsigned int a, b, c, d;
    sscanf(ip, "%u.%u.%u.%u", &a, &b, &c, &d);
    return (a << 24) | (b << 16) | (c << 8) | d;
}
void intToIp(unsigned int ip, char *buffer) {
    sprintf(buffer, "%u.%u.%u.%u", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
}
int main() {
    char ipStr[20];
    int prefix;
    printf("Enter IP address: ");
    scanf("%s", ipStr);
    printf("Enter prefix length: ");
    scanf("%d", &prefix);
    unsigned int ip = ipToInt(ipStr);
    unsigned int mask = ~((1 << (32 - prefix)) - 1);
    int newPrefix = prefix + 1;
    unsigned int newMask = ~((1 << (32 - newPrefix)) - 1);
    int num = 2;
    int hosts = (1 << (32 - newPrefix)) - 2;   
    printf("No of subnets: %d\n", num);
    printf("No of hosts: %d\n", hosts);
    printf("\nBroadcast Tree:\n\n");
    for (int i = 0; i < num; i++) {
        unsigned int network = (ip & mask) + (i * (1 << (32 - newPrefix)));
        unsigned int broadcast = network | ~newMask;
        char netAddr[20], broadAddr[20], newMaskStr[20];
        intToIp(network, netAddr);
        intToIp(broadcast, broadAddr);
        intToIp(newMask, newMaskStr);
        printf("Subnet %d:\n", i + 1);
        printf("Network Address: %s\n", netAddr);
        printf("Broadcast Address: %s\n", broadAddr);
        printf("Subnet Mask: %s\n", newMaskStr);
        printf("Hosts: ");
        for (int j = 1; j <= hosts; j++) {
            char hostAddrStr[20];
            intToIp(network + j, hostAddrStr);
            printf("%s ", hostAddrStr);
        }
        printf("\n\n");
    }
    return 0;
}
