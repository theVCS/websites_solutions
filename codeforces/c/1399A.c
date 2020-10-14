#include<stdio.h>
#include<limits.h>

int main()
{
    int t, n, list[1000], sum, var, first;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        sum = 0;
        first = INT_MAX;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &var);

            if (first > var)
            {
                first = var;
            }
            

            sum += var;
        }

        if ((sum >= first*n) && (sum <= first*n + (n*(n - 1)/2)))
        {
            list[i] = 1;
        }
        else
        {
            list[i] = 0;
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