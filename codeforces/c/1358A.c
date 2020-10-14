#include<stdio.h>

int lantern_calculator(int a, int b);
int min(int a, int b);

int main()
{
    int t, n, m;
    scanf("%d", &t);
    int list[t];

    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &n, &m);
        list[i] = lantern_calculator(n, m);
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("%d\n", list[i]);
    }
    

    return 0;
}

int lantern_calculator(int a, int b)
{
    int value = min(a*((b + 1)/2), ((a + 1)/2)*b);
    if (a > 2 || b > 2 && a != 1 && b != 1)
    {
        return value - 1;
    }
    else
    {
        return value;
    }
}

int min(int a, int b)
{
    return a < b ? a : b;
}