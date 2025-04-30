/* Sliding Window Protocol using the Go-Back-N  mechanism
Sample input:
Enter total number of frames: 3
Enter window size: 2

Sample Output:
[Sender] Starting Sliding Window Protocol with Go-Back-N.
[Sender] Frame 0 sent successfully.
[Sender] Frame 1 sent successfully.
[Receiver] ACK for Frame 0 received successfully.
[Sender] Sliding window. Base frame is now 1.
[Receiver] ACK for Frame 1 received successfully.
[Sender] Sliding window. Base frame is now 2.
[Sender] Frame 2 sent successfully.
[Receiver] ACK for Frame 2 received successfully.
[Sender] Sliding window. Base frame is now 3.
[Sender] All frames sent and acknowledged successfully.
[Sender] Transmission completed.

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#define TIMEOUT 3
int TOTAL_FRAMES = 10;
int WINDOW_SIZE = 4;
bool *acks;
bool send_frame(int frame) {
    if ((rand() % 100) < 20) {
        printf("[Sender] Frame %d lost.\n", frame);
        return false;
    }
    printf("[Sender] Frame %d sent successfully.\n", frame);
    return true;
    }
bool receive_ack(int frame) {
    if ((rand() % 100) < 14) {
        printf("[Receiver] ACK for Frame %d lost.\n", frame);
        return false;
}
    printf("[Receiver] ACK for Frame %d received successfully.\n", frame);
    return true;
    }
void sliding_window_protocol() {
    printf("[Sender] Starting Sliding Window Protocol with Go-Back-N.\n");
    int base = 0;
    int next_frame = 0;
    while (base < TOTAL_FRAMES) {
        while (next_frame < base + WINDOW_SIZE && next_frame < TOTAL_FRAMES) {
            if (send_frame(next_frame)) {
                next_frame++;
            } 
        else {
                next_frame = base;
                break;
            }
        }
        sleep(TIMEOUT);
        for (int i = base; i < next_frame && i < TOTAL_FRAMES; i++) {
            if (!acks[i] && receive_ack(i)) {
                acks[i] = true;
            }
        }
        while (base < TOTAL_FRAMES && acks[base]) {
            base++;
            printf("[Sender] Sliding window. Base frame is now %d.\n", base);
        }
        if (base < TOTAL_FRAMES && !acks[base]) {
            printf("[Sender] Timeout occurred. Retransmitting from Frame %d.\n", base);
            next_frame = base; 
        }
    }
    printf("[Sender] All frames sent and acknowledged successfully.\n");
    printf("[Sender] Transmission completed.\n");
}
int main() {
    srand(time(NULL));
    acks = (bool *)malloc(TOTAL_FRAMES * sizeof(bool));
    for (int i = 0; i < TOTAL_FRAMES; i++) 
    {
    acks[i] = false;
    }
    sliding_window_protocol();
    free(acks);
    return 0;
}