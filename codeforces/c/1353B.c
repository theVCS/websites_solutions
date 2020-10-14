#include<stdio.h>

int max_sum(int a[], int b[], int a_pos, int b_pos, int k, int n);
void quickSort(int arr[], int left, int right);
void swap(int *a, int *b);
int partition(int arr[], int left, int right);

int main(int argc, char const *argv[])
{
    int t, pos, i;
    int n, k;
    int a[30], b[30];
    scanf("%d", &t);    
    int result[t];
    for (i = 0; i < t; i++)
    {
        scanf("%d%d", &n, &k);
        for (pos = 0; pos < n; pos++)
        {
            scanf("%d", a + pos);
        }

        for (pos = 0; pos < n; pos++)
        {
            scanf("%d", b + pos);
        }

        quickSort(a, 0, n - 1);
        quickSort(b, 0, n - 1);

        result[i] = max_sum(a, b, n, n, k, n);
    }
    
    for (i = 0; i < t; i++)
    {
        printf("%d\n", result[i]);
    }
    

    return 0;
}

int max_sum(int a[], int b[], int a_pos, int b_pos, int k, int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if ((a[a_pos - 1] < b[b_pos - 1]) && k)
    {
        return b[b_pos - 1] + max_sum(a, b, a_pos, b_pos - 1, k - 1, n - 1);
    }
    else
    {
        return a[a_pos - 1] + max_sum(a, b, a_pos - 1, b_pos, k, n - 1);
    }
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int position = partition(arr, left, right);
        quickSort(arr, left, position - 1);
        quickSort(arr, position + 1, right);
    }
}

int partition(int arr[], int left, int right)
{
    int last_element = arr[right];
    int left_pointer = left - 1, value;
    for (int i = left; i <= right; i++)
    {
        if (arr[i] < last_element)
        {
            left_pointer++;
            swap(arr + left_pointer, arr + i);
        }
    }
    left_pointer++;
    swap(arr + left_pointer, arr + right);
    return left_pointer;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}