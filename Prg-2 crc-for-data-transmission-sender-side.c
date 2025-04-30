/*  Write a program to compute the CRC value for a given data string and generator polynomial. 

Sample Input:

Enter data: 101101
Enter polynomial: 1101

Sample Output:

Final data to be sent: 101101101
*/
#include <stdio.h>
#include <string.h>
void xorDivision(char dividend[], char divisor[], char remainder[]) {
    int len_divisor = strlen(divisor);
    int len_dividend = strlen(dividend);
    char temp[len_divisor + 1];
    strncpy(temp, dividend, len_divisor);
    temp[len_divisor] = '\0';
    for (int i = 0; i <= len_dividend - len_divisor; i++){
        if (temp[0] == '1'){
            for (int j = 0; j < len_divisor; j++){
                temp[j] = (temp[j] == divisor[j]) ? '0' : '1';
            }
        }
        if (i < len_dividend - len_divisor){
            memmove(temp, temp + 1, len_divisor - 1);
            temp[len_divisor - 1] = dividend[i + len_divisor];
        }
    }
    strncpy(remainder, temp + 1, len_divisor - 1);
    remainder[len_divisor - 1] = '\0';
}
int main(){
    char data[100], generator[100], remainder[100], finalData[100];
    printf("Enter data : ");
    scanf("%s", data);
    printf("Enter polynomial: ");
    scanf("%s", generator);
    int len_data = strlen(data);
    int len_gen = strlen(generator);
    char paddedData[200];
    strcpy(paddedData, data);
    for (int i = 0; i < len_gen - 1; i++){
        strcat(paddedData, "0");
    }
    xorDivision(paddedData, generator, remainder);
    strcpy(finalData, data);
    strcat(finalData, remainder);
    printf("Final data to be sent: %s\n", finalData);
    return 0;
}