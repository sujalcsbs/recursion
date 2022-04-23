#include<stdio.h>

int power(int n){
    if(n == 1){
        return 2;
    }
    return 2 * power(n-1);
}
 
int main()
{
    printf("%d",power(10));
    return 0;
}