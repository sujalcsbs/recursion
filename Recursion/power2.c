#include<stdio.h>
#include<stdlib.h>
 
int power(int base, int expo){
    if(expo == 1){
        return base;
    }
    return base * power(base, expo-1);
}

int main()
{
    printf("%d",power(2,3));
    return 0;
}