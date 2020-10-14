#include<stdio.h>
int main()
{
    long long t, list[10000][2];
    scanf("%lld", &t);
    for (long long i = 0; i < t; i++)
    {
        scanf("%lld%lld", &list[i][0], &list[i][1]);
    }

    for (long long i = 0; i < t; i++)
    {
        if ((list[i][1] - list[i][0]) / list[i][0])
        {
            list[i][1] = list[i][1] - (list[i][1]%list[i][0]);
            printf("%lld\t%lld\n", list[i][0], list[i][1]);
        }
        else
        {
            printf("-1\t-1\n");
        }

    }

    return 0;
}
