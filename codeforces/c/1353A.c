#include<stdio.h>

void max_calculator(long long no_of_value, long long sum);

int main(int argc, char const *argv[])
{
    int t, i;
    scanf("%d", &t);
    long long ques[t][2];
    for (i = 0; i < t; i++)
    {
        scanf("%lld", &ques[i][0]);
        scanf("%lld", &ques[i][1]);
    }
    
    for (i = 0; i < t; i++)
    {
        max_calculator(ques[i][0], ques[i][1]);
    }
    
    return 0;
}

void max_calculator(long long no_of_value, long long sum)
{
    if (no_of_value == 1)
    {
        printf("0\n");
    }
    else if (no_of_value == 2)
    {
        printf("%lld\n", sum);
    }
    else
    {
        printf("%lld\n", 2*sum);
    }
}