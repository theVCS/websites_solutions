#include <stdio.h>
#include <stdlib.h>

#define maxN 100001
#define ll long long int
#define REP(i, a, b) for (int i = a; i <= b; i++)

int n;
ll arr[maxN];
ll prefix[maxN];

int upperBound(int ele)
{
    int start = 1, end = n;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] <= ele && (mid == end || arr[mid + 1] > ele))
            return mid;
        else if (arr[mid] <= ele)
            start = mid + 1;
        else
            end = mid - 1;
    }
}

int lowerBound(int ele)
{
    int start = 1, end = n;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] >= ele && (mid == start || arr[mid - 1] < ele))
            return mid;
        else if (arr[mid] >= ele)
            end = mid - 1;
        else
            start = mid + 1;
    }
}

int cmp(const void *p, const void *q)
{
    return (*(int *)p < *(int *)q);
}

int main()
{
    scanf("%d", &n);

    REP(i, 1, n)
    scanf("%d", arr + i);

    // sort(arr + 1, arr + 1 + n);
    
    REP(i, 1, n)
    prefix[i] = prefix[i - 1] + arr[i];

    REP(i, 1, n)
    printf("%lld ", arr[i]);
    printf("\n");

    int q;
    scanf("%d", &q);

    while (q--)
    {
        int ind1, ind2;
        scanf("%d%d", &ind1, &ind2);
        ind2 = upperBound(ind2);
        ind1 = lowerBound(ind1);
        printf("%lld\n", prefix[ind2] - prefix[ind1 - 1]);
    }

    return 0;
}