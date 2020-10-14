#include<stdio.h>

int main()
{
    int t, arr[1000], n;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        arr[i] = n;
    }
    
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            printf("1\t");
        }
        printf("\n");
    }
    

    return 0;
}
