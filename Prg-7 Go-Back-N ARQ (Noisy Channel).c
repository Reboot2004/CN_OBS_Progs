/* Go-Back-N ARQ (Noisy Channel)
Problem Statement
Simulate the Go-Back-N ARQ where multiple frames are sent in a window, and if an error occurs, all frames after the erroneous one are retransmitted.

Sample Input:
Enter total frames: 4
Enter window size: 2
Sending Frames 1 2
ACK received for Frame 1
Error ! Resending frames from Frame 2
Sending Frames 2 3
ACK received for Frame 2
ACK received for Frame 3
Sending Frames 4
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
    while (i <= frames) {
        printf("Sending Frames ");
        for (int j = i; j <= frames && j < i + size; j++) {
            printf("%d ", j);
        }
        printf("\n");
        int error_occurred = 0;
        for (int j = i; j <= frames && j < i + size; j++) {
            if (rand() % 2) {  
                printf("Error! Resending frames from Frame %d\n", j);
                error_occurred = 1;
                i = j;
                break;
            }
            printf("ACK received for Frame %d\n", j);
        }
        if (!error_occurred) {
            i += size;
        }
    }
    printf("All frames sent successfully!\n");
    return 0;
}

