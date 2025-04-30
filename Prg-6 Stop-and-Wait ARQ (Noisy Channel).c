/* Stop-and-Wait ARQ (Noisy Channel)

Sample Input:
Enter no of frames: 3
Sample Output:
Sending Frame 1
ACK received for Frame 1
Sending Frame 2
Error ! Retransmitting Frame 2
ACK received for Frame 2
Sending Frame 3
ACK received for Frame 3
All frames sent successfully!
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int frames, frame = 0;
    printf("Enter no of frames: ");
    scanf("%d", &frames);
    srand(time(0));
    while (frame < frames) {
        printf("Sending Frame %d\n", frame);
        if (rand() % 3 == 0) {
            printf("Error! Retransmitting Frame %d\n", frame);
        } else {
            printf("ACK received for Frame %d\n", frame);
            frame++;
        }
    }
    printf("All frames sent successfully!\n");
    return 0;
}
