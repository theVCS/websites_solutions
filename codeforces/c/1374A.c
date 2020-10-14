#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    long long x, y, n, list[t], result;

    for (int i = 0; i < t; i++)
    {
        scanf("%lld%lld%lld", &x, &y, &n);
        result = (n - y)/x;
        list[i] = result*x + y;
    }

    for (int i = 0; i < t; i++)
    {
        printf("%lld\n", list[i]);
    }
    
    return 0;
}
