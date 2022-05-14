#include<stdio.h>
#include<stdlib.h>

int * count_sort(int *arr, int n)
{
    int i, j = 0, min = 1e6, max = -1e6, *index, *ans;
    for(i = 0; i < n; i++)
    {
        if(arr[i] < min)    min = arr[i];
        if(arr[i] > max)    max = arr[i];
    }
    min = (-min);
    index = (int *)malloc(sizeof(int) * (max+(min)+1));
    ans = (int *)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
    {
        index[arr[i] + min]++;
    }
    for(i = 0; i < (max+min+1); i++)
    {
        while(index[i] > 0)
        {
            ans[j++] = i - min;
            index[i]--;
        }
    }
    return ans;
}
 
int main()
{
    int *arr, *ans, i, n;
    printf("Enter the size of the array: ");    scanf("%d",&n);
    arr = (int *)malloc(sizeof(int) * n);
    printf("Enter the elements of the array: ");   
    for(i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    ans = count_sort(arr, n);
    for(i = 0; i < n; i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}