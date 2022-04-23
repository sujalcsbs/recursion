#include<stdio.h>

typedef struct{
    int feet;
    int inches;
}dist;
 
int main()
{
    dist d1, d2, ans;
    scanf("%d %d",&d1.feet, &d1.inches);
    scanf("%d %d",&d2.feet, &d2.inches);
    ans.feet = ans.inches = 0;
    printf("%d %d\n",d1.feet, d1.inches);
    printf("%d %d\n",d2.feet, d2.inches);
    ans.inches = (d1.inches + d2.inches)%12;
    ans.feet = (d1.feet + d2.feet + (d1.inches+d2.inches)/12);
    printf("%d %d",ans.feet, ans.inches);
    return 0;
}