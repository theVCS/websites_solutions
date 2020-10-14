#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
    int t, n;
    scanf("%d", &t);
    long long gifts[2][50], min_candies, min_oranges, steps, result[t], i, j, k;

    for (k = 0; k < t; k++)
    {
        scanf("%d", &n);
        steps = 0;
        min_candies = __LONG_LONG_MAX__;
        min_oranges = __LONG_LONG_MAX__;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%lld", &gifts[i][j]);

                if (i == 0 && min_candies > gifts[i][j])
                {
                    min_candies = gifts[i][j];
                }
                else if (i == 1 && min_oranges > gifts[i][j])
                {
                    min_oranges = gifts[i][j];
                }
            }
        }

        for (i = 0; i < n; i++)
        {
            if (gifts[0][i] > min_candies && gifts[1][i] > min_oranges)
            {
                if (gifts[0][i] - min_candies > gifts[1][i] - min_oranges)
                {
                    steps += gifts[0][i] - min_candies;
                }
                else
                {
                    steps += gifts[1][i] - min_oranges;
                }
            }
            else if (gifts[0][i] > min_candies)
            {
                steps += gifts[0][i] - min_candies;
            }
            else
            {
                steps += gifts[1][i] - min_oranges;
            }
        }
       result[k] = steps;
    }


    for (i = 0; i < t; i++)
    {
        printf("%lld\n", result[i]);
    }
    

    return 0;
}