/*Stop-and-Wait Protocol (Noiseless Channel)
Problem Statement:

Simulate the Stop-and-Wait Protocol where the sender sends one frame at a time and waits for an acknowledgment (ACK) from the receiver before sending the next frame.

Steps to Implement:
The sender sends a frame.
The receiver receives the frame and sends an acknowledgment.
The sender waits for ACK before sending the next frame.
Repeat until all frames are sent.

Sample Input:
Enter the number of frames: 3
Sample Output:
Sending Frame 1
ACK received for Frame 1
Sending Frame 2
ACK received for Frame 2
Sending Frame 3
ACK received for Frame 3
All frames sent successfully!
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int frames ;
    printf("Enter the number of frames: ") ;
    scanf("%d", &frames);
    
    for(int i  = 1; i <= frames; i++) {
        printf("Sending Frame %d\n", i);
        printf("ACK received for Frame %d\n", i);
    }
    printf("All frames sent successfully!");
    return 0;
}