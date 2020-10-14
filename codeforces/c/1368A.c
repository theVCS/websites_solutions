#include<stdio.h>

int count(long long a, long long b, long long n);

int main()
{
    int t;
    scanf("%d", &t);
    int list[t];
    long long a, b, n;
    for (int i = 0; i < t; i++)
    {
        scanf("%lld%lld%lld", &a, &b, &n);
        list[i] = count(a, b, n);
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("%d\n", list[i]);
    }
    

    return 0;
}


int count(long long a, long long b, long long n)
{
    if (a > n || b > n)
    {
        return 0;
    }
    else if (a > b)
    {
        return 1 + count(a, b + a, n);
    }
    else
    {
        return 1 + count(a + b, b, n);
    }
    
}