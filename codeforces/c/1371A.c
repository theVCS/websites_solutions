#include<stdio.h>

int main()
{
    int t;
    long long n, list[1000];
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%lld", &n);
        list[i] = (n + 1)/2;
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("%lld\n", list[i]);
    }
    

    return 0;
}
