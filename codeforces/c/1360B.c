#include<stdio.h>
#include<math.h>
#include<limits.h>

void quickSort(int *list, int left, int right);
int partition(int *list, int left, int right);
void swap(int *a, int *b);

int main()
{
    int t, n, a, b, value_list[50], i, j, min;
    scanf("%d", &t);
    int list[t];

    for (i = 0; i < t; i++)
    {
        min = INT_MAX;
        scanf("%d", &n);

        for (j = 0; j < n; j++)
        {
            scanf("%d", &value_list[j]);
        }

        quickSort(value_list, 0, n - 1);

        for (j = 0; j < n - 1; j++)
        {
            if (min > value_list[j + 1] - value_list[j])
            {
                min = value_list[j + 1] - value_list[j];
            }
        }
        list[i] = min;
    }

    for (i = 0; i < t; i++)
    {
        printf("%d\n", list[i]);
    }

    return 0;
}

void quickSort(int *list, int left, int right)
{
    if (left < right)
    {
        int position = partition(list, left, right);
        quickSort(list, left, position - 1);
        quickSort(list, position + 1, right);
    }
}

int partition(int *list, int left, int right)
{
    int last_element = *(list + right);
    int left_pointer = left - 1, value;
    for (int i = left; i <= right; i++)
    {
        if (*(list + i) < last_element)
        {
            left_pointer++;
            swap(list + left_pointer, list + i);
        }
    }
    left_pointer++;
    swap(list + left_pointer, list + right);
    return left_pointer;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}