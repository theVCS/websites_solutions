#include<stdio.h>
#include<string.h>

int main()
{
    int t, n, m, list_1[1000], list_2[1000];
    scanf("%d", &t);
    int list[t], i, j, k;

    // used to initialize array with value -1
    // memset(list, -1, sizeof(list)/sizeof(list[0]));

    for (int i = 0; i < t; i++)
    {
        list[i] = -1;
    }

    for (i = 0; i < t; i++)
    {
        scanf("%d%d", &n, &m);

        for (j = 0; j < n; j++)
        {
            scanf("%d", &list_1[j]);
        }

        for (j = 0; j < m; j++)
        {
            scanf("%d", &list_2[j]);
        }

        for (j = 0; j < n; j++)
        {
            for (k = 0; k < m; k++)
            {
                if (list_1[j] == list_2[k])
                {
                    list[i] = list_1[j];
                    k = m;
                    j = n;
                }

            }
        }
    }

    for (i = 0; i < t; i++)
    {
        if (list[i] == -1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            printf("1   %d\n", list[i]);
        }

    }


    return 0;
}
