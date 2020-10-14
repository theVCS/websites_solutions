#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

void removeDigits(int *list, int size, int position);
void quickSort(int *list, int left, int right);
int partition(int *list, int left, int right);
void swap(int *, int *);

int top = -1;

int main()
{
    int n, i, j;
    // scanf("%d", &n);
    n = rand()%100 + 1;
    int list[n];

    for (i = 0; i < n; i++)
    {
        // scanf("%d", &list[i]);
        list[i] = rand()%1000 + 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d\t", list[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (list[i] == INT_MAX)
            {
                break;
            }

            if (list[i] == list[j] && list[j] != INT_MAX)
            {
                list[j] = INT_MAX;
            }
        }
    }

    for (i = 1; i < n; i++)
    {
        if (list[i] == INT_MAX)
        {
            removeDigits(list, n, i);
            n--;
            i--;
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d\t", list[i]);
    }
    printf("\n");

    // just for checking purpose
    quickSort(list, 0, n - 1);

    for (i = 0; i < n; i++)
    {
        printf("%d\t", list[i]);
    }

    return 0;
}

void removeDigits(int *list, int size, int position)
{
    int left = position;
    int right = left + 1;

    while (right < size)
    {
        list[left] = list[right];
        left++;
        right++;
    }
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