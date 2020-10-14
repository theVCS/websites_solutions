#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    int list[t];
    long long n;
    for (int i = 0; i < t; i++)
    {
        scanf("%lld", &n);
        if (n%2)
        {
            list[i] = 0;
        }
        else
        {
            list[i] = 1;
        }
    }

    for (int i = 0; i < t; i++)
    {
        if (list[i] == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        
    }
    
    
    return 0;
}
