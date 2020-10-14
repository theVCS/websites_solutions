#include<stdio.h>
#include<stdlib.h>

void remove_value(int arr[], int value, int size);

int main()
{
    int t, value_list[400][100], no_of_value_list[50], no_of_values;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &no_of_values);
        no_of_value_list[i] = no_of_values;
        for (int j = 0; j < no_of_values*2; j++)
        {
            scanf("%d", &value_list[i][j]);
        }
    }

    for (int i = 0; i < t; i++)
    {
        no_of_values = no_of_value_list[i];

        for (int j = 1; j <= no_of_values; j++)
        {
            remove_value(value_list[i], j, no_of_values);
        }
    }

    for (int i = 0; i < t; i++)
    {
        no_of_values = no_of_value_list[i];

        for (int j = 0; j < 2*no_of_values; j++)
        {
            if (value_list[i][j] !=  -1)
            {
                printf("%d\t", value_list[i][j]);
            }

        }
        printf("\n");
    }
    return 0;
}

void remove_value(int arr[], int value, int size)
{
    for (int i = 0; i < 2*size; i++)
    {
        if (value == arr[i])
        {
            arr[i] = -1;
            break;
        }
    }
}