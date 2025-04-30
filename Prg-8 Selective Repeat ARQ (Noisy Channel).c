/* Selective Repeat ARQ (Noisy Channel)
Problem Statement:
Simulate the Selective Repeat ARQ, where only the erroneous frame is retransmitted instead of all frames after it.

Sample Input:
Enter total frames: 4
Enter window size: 2
Sending Frames 1 2 
ACK received for Frame 1
Error ! Retransmitting Frame 2
ACK received for Frame 2
Sending Frames 3 4 
ACK received for Frame 3
ACK received for Frame 4
All frames sent successfully!

*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    int frames, size;
    printf("Enter total frames: ");
    scanf("%d", &frames);
    printf("Enter window size: ");
    scanf("%d", &size);
    
    int i = 1;
    
    while(i <= frames) {

        printf("Sending Frames ");
        for(int j = i; j <= frames && i + size > j; j++) {
            printf("%d ", j);
        }
        printf("\n");
        for(int j = i; j <= frames && i + size > j; j++) {
            while(rand() %2) {
                printf("Error detected in Frame %d! Retransmitting Frame %d\n",j,j);
            }
            printf("ACK received for Frame %d\n", j);
        }
        i+=size;
        
    }
    printf("All frames sent successfully!\n");
    
}