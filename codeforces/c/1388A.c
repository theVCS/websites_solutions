#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);
    unsigned long long *result = (unsigned long long *)malloc(t * sizeof(unsigned long long));
    unsigned long long number;
    for (int i = 0; i < t; i++)
    {
        scanf("%llu", &number);
        if (number < 31)
        {
            *(result + i) = -1;
        }
        else
        {
            *(result + i) = number;
        }
    }

    for (int i = 0; i < t; i++)
    {
        if (*(result + i) == -1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            if (*(result + i) == 36)
            {
                printf("5 6 10 15\n");
            }
            else if (*(result + i) == 40)
            {
                printf("3 6 10 21\n");
            }
            else if (*(result + i) == 44)
            {
                printf("6 7 10 21\n");
            }
            else
            {
                printf("6 10 14 %llu\n", *(result + i) - 30);
            }
        }
    }

    return 0;
}
