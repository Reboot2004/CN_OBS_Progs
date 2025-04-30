/* CSMA/CD (Carrier Sense Multiple Access with Collision Detection) is a network protocol used for managing data transmission over a shared communication medium. It ensures that devices listen to the channel before sending data and detect collisions when two devices transmit simultaneously. After a collision, devices wait for a random amount of time before retrying.
Steps for Implementing CSMA/CD Protocol in C Language.

Steps:
Initialization: Define variables for communication status, collision detection, and retransmission attempts.
Listen to Channel (Carrier Sense): Check if the channel is free or busy.
Transmit Data: If the channel is free, transmit data.
Collision Detection: Check if a collision occurs during transmission.
Backoff Mechanism: If a collision is detected, stop transmission and wait for a random time before retrying.
Retry Limit: Repeat the process until data is successfully transmitted or maximum attempts are reached.
Display Output: Show transmission status with or without collisions.


Sample input & output:
Enter the numbevr of stations: 3

Checking station 1...
Channel is free. Station 1 is transmitting.
Checking station 2...
Channel is free. Station 2 is transmitting.
Collision detected! Retransmitting after random backoff time.
Checking station 3...
Channel is free. Station 3 is transmitting.
Transmission successful.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main() {
    int ch;
    printf("Enter no of stations: ");
    scanf("%d", &ch);
    srand(time(NULL));
    for (int i = 1; i <= ch; i++) {
        printf("\nChecking station %d...\n", i);
        printf("Channel is free. Station %d is transmitting...\n", i);
        if (rand() % 10 > 7) { 
            int backoff = rand() % 3 + 1;
            printf("Collision detected! Retransmitting after random backoff time");
            sleep(backoff);
            printf("Station %d retransmitting...\n", i);
        }
    }
    printf("Transmission successful");
    return 0;
}
