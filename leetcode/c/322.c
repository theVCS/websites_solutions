#include <stdio.h>
#include <limits.h>

int coinChange(int *coins, int size, int total_money);
int min(int a, int b);
void swap(int *a);

int main()
{
    int coins[] = {1, 2};
    int amount = 3, size = 2, count = 0;
    printf("%d", coinChange(coins, size, amount));
    return 0;
}

int coinChange(int *coins, int size, int total_money)
{
    if (total_money == 0)
    {
        return 0;
    }
    else if (size == 0)
    {
        return -1;
    }    
    else if (size == 1)
    {
        if (total_money % coins[0])
        {
            return -1;
        }
        else
        {
            return total_money / coins[0];
        }
    }

    else if (size == 2)
    {   
        int a, b, total_coins;
        if (coins[0] > coins[1])
        {
            a = coins[0];
            b = coins[1];
        }
        else
        {
            a = coins[1];
            b = coins[0];
        }
        
        
        if ((total_money - (total_money / a)*a)%b)
        {
            return -1;
        }
        else
        {
            return (total_coins/a) + (total_money - (total_money / a)*a)/b;
        }
        
    }
    

    else
    {
        int dp[size + 1][total_money + 1];

        for (int i = 0; i < size + 1; i++)
        {
            for (int j = 0; j < total_money + 1; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = 2147483647 - total_money;
                }
                else if (j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (i == 1)
                {
                    if (j % coins[1])
                    {
                        dp[i][j] = 2147483647 - total_money;
                    }
                    else
                    {
                        dp[i][j] = j / coins[1];
                    }
                }
                else if (coins[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
            }
        }
        return dp[size][total_money] - 1;
    }
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void swap(int *a)
{
    if (*a > *(a + 1))
    {
        int t = *a;
        *a = *(a + 1);
        *(a + 1) = t;
    }
}