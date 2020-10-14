#include<stdio.h>

int area_calculator(int a, int b);

int main()
{
    int t, a, b;
    scanf("%d", &t);
    int list[t];

    for (int i = 0; i < t; i++)
    {
        scanf("%d%d", &a, &b);
        if (a > b)
        {
            list[i] = area_calculator(a, b);
        }
        else
        {
            list[i] = area_calculator(b, a);
        }
    }

    for (int i = 0; i < t; i++)
    {
        printf("%d\n", list[i]);
    }
    

    return 0;
}


int area_calculator(int a, int b)
{
    if (a == b)
    {
        return 4*a*a;
    }
    else
    {
        if (a > 2*b)
        {
            return a*a;
        }
        else if (a < 2*b)
        {
            return 4*b*b;
        }
        else
        {
            return a*a;
        }
    }
}