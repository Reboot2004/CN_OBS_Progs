/*Generate a Valid CIDR Block
Problem Statement:
Given a starting IP address and a block size, generate all the IP addresses in the block.
*/
#include <stdio.h>
#include <stdlib.h>
void parseIP(const char *ip, int *octet) {
    sscanf(ip, "%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]);
}
void getCidrBlock(const char *ip, int block) {
    int octet[4];
    parseIP(ip, octet);
    for (int i = 0; i < block; i++) {
        int total = octet[3] + i;
        int octet3 = total % 256;
        int carry = total / 256;
        printf("%d.%d.%d.%d\n", octet[0], octet[1], octet[2] + carry, octet3);
    }
}
int main() {
    char ip[16];
    int block;
    printf("Enter IP Address: ");
    scanf("%15s", ip);
    printf("Enter Block Size: ");
    scanf("%d", &block);
    if (block <= 0 || block > 256) {
        printf("Invalid block size.\n");
        return 1;
    }
    getCidrBlock(ip, block);
    return 0;
}
/*
Enter IP Address: 192.168.1.16
Enter Block Size: 8
192.168.1.16
192.168.1.17
192.168.1.18
192.168.1.19
192.168.1.20
192.168.1.21
192.168.1.22
192.168.1.23

*/