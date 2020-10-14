#include<stdio.h>

int main()
{
    int t, n, list[100];
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        if (n <= 3)
        {
            list[i] = 1;
        }
        else
        {
            n -= n%2;
            list[i] = n/2;
        }
        
    }

    for (int i = 0; i < t; i++)
    {
        printf("%d\n", list[i]);
    }
    

    return 0;
}
