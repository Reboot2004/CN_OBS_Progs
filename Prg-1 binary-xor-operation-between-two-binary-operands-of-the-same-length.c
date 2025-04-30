/*Write a program to perform a binary XOR operation between two binary operands of the same length. 

Sample Input/Output 1:

Enter first binary no: 1101
Enter second binary no: 1011
Result: 0110

*/
#include <stdio.h>
#include <string.h>
void binaryXOR(char *bin1, char *bin2, char *result){
    int length = strlen(bin1);
    for (int i = 0; i < length; i++){
        result[i] = (bin1[i] == bin2[i]) ? '0' : '1';
    }
    result[length] = '\0';
}
int main(){
    char bin1[100], bin2[100], result[100];
    printf("Enter first binary no: ");
    scanf("%s", bin1);
    printf("Enter second binary no: ");
    scanf("%s", bin2);
    if (strlen(bin1) != strlen(bin2)){
        printf("Binary numbers must have the same length.\n");
        return 1;
    }
    binaryXOR(bin1, bin2, result);
    printf("Result : %s\n", result);
    return 0;
}