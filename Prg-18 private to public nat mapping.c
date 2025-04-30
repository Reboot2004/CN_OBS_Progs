/*
write a c program for private to public nat mapping
*/
#include <stdio.h>
#include <string.h>
#define MAX 100
#define IP_LEN 20
int main() {
    char privateIPs[MAX][IP_LEN];
    char natIP[IP_LEN];
    char searchIP[IP_LEN];
    int n, found = 0;
    printf("Enter number of devices: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter private IP %d: ", i + 1);
        scanf("%s", privateIPs[i]);
    }
    printf("Enter public NAT IP: ");
    scanf("%s", natIP);
    printf("Enter a private IP to search: ");
    scanf("%s", searchIP);
    printf("Private IPs registered under NAT:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", privateIPs[i]);
    }
    printf("Public NAT IP: %s\n", natIP);
    for (int i = 0; i < n; i++) {
        if (strcmp(privateIPs[i], searchIP) == 0) {
            printf("Search result:\n%s → %s\n", searchIP, natIP);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Search result:\n%s not found under NAT\n", searchIP);
    }
    return 0;
}
/*
output:
Enter number of devices: 3
Enter private IP 1: 192.168.1.2
Enter private IP 2: 192.168.1.3
Enter private IP 3: 192.168.1.4
Enter public NAT IP: 203.0.113.100
Enter a private IP to search: 192.168.1.3
Private IPs registered under NAT:
192.168.1.2
192.168.1.3
192.168.1.4
Public NAT IP: 203.0.113.100
Search result:
192.168.1.3 → 203.0.113.100
*/