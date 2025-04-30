/*
Write a C program to simulate the CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance) protocol. Your program should:


Sample Output:
Enter no of stations: 2
Checking Station 1...
Channel is busy. Station 1 waiting for random backoff time of 2 seconds.
Channel is free. Station 1 is transmitting...
Station 1: Transmission successful. ACK received.

Checking Station 2...
Channel is free. Station 2 is transmitting...
Station 2: Transmission successful. ACK received.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int ch;
    printf("Enter no of stations: ");
    scanf("%d", &ch);
    srand(time(NULL)); 
    for (int i = 1; i <= ch; i++) {
        printf("Checking Station %d...\n", i);
        if (i % 2 != 0) {
            int backoff = rand() % 3 + 1;
            printf("Channel is busy. Station %d waiting for random backoff time of %d seconds.\n", i, backoff);
            sleep(backoff);
        }
        printf("Channel is free. Station %d is transmitting...\n", i);
        printf("Station %d: Transmission successful. ACK received.\n\n", i);
    }
    return 0;
}
