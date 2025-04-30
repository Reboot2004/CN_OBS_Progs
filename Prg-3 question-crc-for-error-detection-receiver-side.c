/* Write a program to check if a received data string contains errors using a given generator polynomial. 

Sample Input:

Enter data: 101101101
Enter polynomial: 1101

Sample Output:

No error detected

*/
#include <stdio.h>
#include <string.h>
void xorOperation(char *dividend, char *generator, int genLen){
    for (int i = 0; i < genLen; i++){
        dividend[i] = (dividend[i] == generator[i]) ? '0' : '1';
    }
}
void checkCRC(char *receivedData, char *generator){
    int dataLen = strlen(receivedData);
    int genLen = strlen(generator);
    char dividend[100];
    strcpy(dividend, receivedData);
    for (int i = 0; i <= dataLen - genLen; i++){
        if (dividend[i] == '1'){
            xorOperation(&dividend[i], generator, genLen);
        }
    }
    for (int i = dataLen - genLen + 1; i < dataLen; i++){
        if (dividend[i] == '1'){
            printf("Error detected\n");
            return;
        }
    }
    printf("No error detected\n");
}
int main(){
    char receivedData[100], generator[100];
    printf("Enter data: ");
    scanf("%s", receivedData);
    printf("Enter polynomial: ");
    scanf("%s", generator);
    checkCRC(receivedData, generator);
    return 0;
}