/*
Question 1: Check if an IP Address is a Valid Block Start
Problem Statement:
Given an IP address and a block size (power of 2), determine if the IP address can be the starting address of a valid CIDR block.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isValidBlockStart(int lastOctet, int blockSize) {
    return (lastOctet % blockSize == 0);
}
int main() {
    char ip[20];
    int blockSize;
    printf("Enter IP Address: ");
    scanf("%s", ip);
    printf("Enter Block Size: ");
    scanf("%d", &blockSize);
    int octets[4];
    if (sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        printf("Invalid IP Address\n");
        return 1;
    }
    if (isValidBlockStart(octets[3], blockSize)) {
        printf("Valid block start\n");
    } else {
        printf("Invalid block start\n");
    }
    return 0;
}
/*
Enter IP Address: 192.168.1.16
Enter Block Size: 8
Valid block start
*/