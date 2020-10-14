#include<limits.h>
#include<stdio.h>

int main()
{
    int t;
    long long x, y, z;
    scanf("%d", &t);
    long long list[t][3];

    for (int i = 0; i < t; i++)
    {
        scanf("%lld%lld%lld", &x, &y, &z);

        if (x != y && y != z && z != x)
        {
            list[i][0] = -1;
        }
        else if (x == y && y == z)
        {
            list[i][0] = x;
            list[i][1] = x;
            list[i][2] = x;
        }
        else
        {
            if (x == y && x > z)
            {
                list[i][0] = x;
                list[i][1] = z;
                list[i][2] = z;
            }
            else if (y == z && y > x)
            {
                list[i][0] = y;
                list[i][1] = x;
                list[i][2] = x;
            }
            else if (z == x && z > y)
            {
                list[i][0] = z;
                list[i][1] = y;
                list[i][2] = y;
            }
            else
            {
                list[i][0] = -1;
            }

        }
    }

    for (int i = 0; i < t; i++)
    {
        if (list[i][0] != -1)
        {
            printf("YES\n%lld\t%lld\t%lld\n", list[i][0], list[i][1], list[i][2]);
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
