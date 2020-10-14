#include <stdio.h>

void round_no_printer(int number, int step);
void counter(int number);
int power(int number, int exp);

int main(int argc, char const *argv[])
{
    int t, i;
    scanf("%d", &t);
    int ques[t];
    for (i = 0; i < t; i++)
    {
        scanf("%d", &ques[i]);
    }

    for (i = 0; i < t; i++)
    {
        counter(ques[i]);
        printf("\n");
    }
    
    return 0;
}

void counter(int number)
{
    int k = number;
    int non_zero_digits = 0;

    while (number)
    {
        if(number%10){
            non_zero_digits++;
        }
        number = number/10;
    }
    printf("%d\n", non_zero_digits);
    round_no_printer(k, 0);
}

void round_no_printer(int number, int step)
{
    if (number)
    {
        int k = number % 10;
        if (k)
        {
            printf("%d\t", k*power(10, step));
        }
        round_no_printer(number / 10, step + 1);
    }
}

int power(int number, int exp)
{   
    int res = 1;
    while (exp)
    {
        res *= number;
        exp--;
    }
    return res;
}