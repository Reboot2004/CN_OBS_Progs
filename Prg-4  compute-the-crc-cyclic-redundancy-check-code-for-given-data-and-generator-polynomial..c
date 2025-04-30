/* Write a program to compute the CRC code for given data and generator polynomial

Sample Input:

Data data: 1101011011
Generator polynomial : 10011
Sample Output:

Transmitted message: 11010110111001

*/
#include <stdio.h>
#include <string.h>

void xorOperation(char* dividend, char* divisor, int len) {
    for (int i = 0; i < len; i++) {
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
    }
}

void calculateCRC(char* data, char* generator, char* remainder) {
    int dataLen = strlen(data);
    int genLen = strlen(generator);
    char temp[genLen];
    strncpy(temp, data, genLen);
    temp[genLen] = '\0';
    for (int i = 0; i <= dataLen - genLen; i++) {
        if (temp[0] == '1') {
            xorOperation(temp, generator, genLen);
        }
        memmove(temp, temp + 1, genLen - 1);
        temp[genLen - 1] = (i + genLen < dataLen) ? data[i + genLen] : '0';
    }
    strncpy(remainder, temp, genLen - 1);
    remainder[genLen - 1] = '\0';
}
int main() {
    char data[100], generator[50], remainder[50], transmittedMessage[150];
    int dataLen, genLen;
    printf("Enter data: ");
    scanf("%s", data);
    printf("generator polynomial: ");
    scanf("%s", generator);
    dataLen = strlen(data);
    genLen = strlen(generator);
    char appendedData[150];
    strcpy(appendedData, data);
    for (int i = 0; i < genLen - 1; i++) {
        strcat(appendedData, "0");
    }
    calculateCRC(appendedData, generator, remainder);
    strcpy(transmittedMessage, data);
    strcat(transmittedMessage, remainder);
    printf("\nTransmitted Message : %s\n", transmittedMessage);
    return 0;
}