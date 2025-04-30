/*
Write a C program to create a NAT table.
*/
#include <stdio.h>
#include <string.h>

#define MAX 100
#define IP_LEN 20

struct NAT {
    char priIP[IP_LEN];
    char pubIP[IP_LEN];
};
int main() {
    struct NAT nattable[MAX];
    int n, found = 0;
    char searchIP[IP_LEN];
    printf("Enter number of NAT entries: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Entry %d:\n", i + 1);
        printf("  Private IP: ");
        scanf("%s", nattable[i].priIP);
        printf("  Public IP: ");
        scanf("%s", nattable[i].pubIP);
    }
    printf("Enter a private IP to search: ");
    scanf("%s", searchIP);
    printf("--- NAT Table ---\n");
    printf("Private IP      Public IP\n");
    for (int i = 0; i < n; i++) {
        printf("%-15s%s\n", nattable[i].priIP, nattable[i].pubIP);
    }
    
    for (int i = 0; i < n; i++) {
        if (strcmp(nattable[i].priIP, searchIP) == 0) {
            printf("Mapped Public IP: %s", nattable[i].pubIP);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Private IP not found in NAT table.");
    }
    return 0;
}
/*
Output:
Enter number of NAT entries: 2
Entry 1:
  Private IP: 192.168.0.22
  Public IP: 203.0.113.10
Entry 2:
  Private IP: 192.168.0.3
  Public IP: 203.0.113.11
Enter a private IP to search: 192.168.0.2
--- NAT Table ---
Private IP      Public IP
192.168.0.22   203.0.113.10
192.168.0.3    203.0.113.11
Private IP not found in NAT table.
*/