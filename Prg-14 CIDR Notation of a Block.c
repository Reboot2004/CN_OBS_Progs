/*
Problem Statement
Given an IP address and a block size, find its CIDR notation.
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int getCIDRSuffix(int block){
    return 32-(int)log2(block);
}
int main(){
    char ipadd[20];
    int block;
    printf("Enter IP Address:");
    scanf("%s",ipadd);
    printf("Enter Block:");
    scanf("%d",&block);
    if(block<=0||block>256||(block&(block-1))!=0){
        return 1;
    }
    int cidr=getCIDRSuffix(block);
    printf("CIDR Notation:%s/%d\n",ipadd,cidr);
    return 0;
}
/*
Enter IP Address: 192.168.1.16  
Enter Block Size: 8  
CIDR Notation: 192.168.1.16/29
*/