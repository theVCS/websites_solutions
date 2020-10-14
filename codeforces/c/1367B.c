#include<stdio.h>

int main()
{
    int t, n, no_of_odds, bad_position, number;
    scanf("%d", &t);
    int list[t];
    for (int i = 0; i < t; i++)
    {
        no_of_odds = 0;
        bad_position = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &number);

            if (number%2 != j%2)
            {
                bad_position++;

            }
            if (number%2)
            {
                no_of_odds++;
            }
        }

        if (no_of_odds == n/2)
        {
            list[i] = bad_position/2;
        }
        else
        {
            list[i] = -1;
        }
    }

    for (int i = 0; i < t; i++)
    {
        printf("%d\n", list[i]);
    }


    return 0;
}
