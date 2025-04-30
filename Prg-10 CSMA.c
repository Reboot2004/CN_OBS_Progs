/*
Question:   Write a C program to simulate CSMA (Carrier Sense Multiple Access) protocol where multiple devices check if the channel is idle before transmission.
Sample Output:
Device A is trying to send data...
Device A successfully transmitted data.
Device B is trying to send data...
Device B successfully transmitted data.
Device C is trying to send data...
Device C successfully transmitted data.
*/
#include<stdio.h>
int main() {
    char ch = 'A';
    
    for(int i = 0; i < 3; i++) {
        printf("Device %c is trying to send data...\n", ch);
        printf("Device %c successfully transmitted data.\n", ch);
        ch = (char) (ch + 1);
    }
    return 1;
}