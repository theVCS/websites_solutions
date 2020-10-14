#include<stdio.h>
#include<string.h>

void RemoveChars(char *s, int position, int size);

int main()
{
    int t;
    scanf("%d", &t);
    char string[100];
    char result[t][100];

    for (int i = 0; i < t; i++)
    {
        scanf("%s", string);
        for (int j = 2; j < strlen(string); j++)// here j is not increased by 2 because after removing a element next repaeating element will come at the next location/
        {
            RemoveChars(string, j, strlen(string));
        }
        strcpy(result[i], string);
    }

    for (int i = 0; i < t; i++)
    {
        printf("%s", result[i]);
        printf("\n");
    }

    return 0;
}

void RemoveChars(char *s, int position, int size)
{
    int left = position, right = position + 1;

    while (right < size)
    {
        s[left] = s[right];
        right++;
        left++;
    }
    s[left] = '\0';
}