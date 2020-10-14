#include <string.h>
#include <stdio.h>

int score_cal(char string[]);
int next_one(char string[], int current);
int next_zero(char string[], int current);
void push(int value);
int pop();
void quickSort(int arr[], int left, int right);
void swap(int *a, int *b);
int partition(int arr[], int left, int right);

int stack[100];
int top = -1;

int main()
{
    int t, i;
    scanf("%d", &t);
    char string[100];
    int result[t];

    for (i = 0; i < t; i++)
    {
        fflush(stdin);
        scanf("%s", string);
        result[i] = score_cal(string);
        top = -1;
    }

    for (i = 0; i < t; i++)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}

int score_cal(char string[])
{
    int right = next_one(string, 0);
    int left = 0;

    if (right == strlen(string))
    {
        return 0;
    }
    while (right < strlen(string))
    {
        left = right;
        right = next_zero(string, left);
        push(right - left);
        right = next_one(string, right);
    }
    int arr[top + 1], t = top + 1, sum = 0;
    while (top + 1)
    {
        arr[top] = pop();
    }
    quickSort(arr, 0, t - 1);
    t--;

    while (t > -1)
    {
        sum += arr[t];
        t -= 2;
    }
    

    return sum;
}

int next_one(char string[], int current)
{
    while (string[current] == '0' && current < strlen(string))
    {
        current++;
    }
    return current;
}

int next_zero(char string[], int current)
{
    while (string[current] == '1' && current < strlen(string))
    {
        current++;
    }
    return current;
}

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
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