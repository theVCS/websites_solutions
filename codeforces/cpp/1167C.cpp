/*
https://codeforces.com/problemset/problem/1167/C
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 500001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[maxN];

int find(int a)
{
    if (arr[a] < 0)
    {
        return a;
    }
    else
    {
        return arr[a] = find(arr[a]);
    }
}

void merge(int a, int b)
{
    if (arr[a] > arr[b])
        swap(a, b);

    arr[a] += arr[b];
    arr[b] = a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, len, a, b;

    cin >> n >> m;

    REP(i, 1, n + 1)
    arr[i] = -1;

    REP(i, 0, m)
    {
        cin >> len;

        if (len)
        {
            cin >> a;
            a = find(a);
            len--;
        }

        REP(j, 0, len)
        {
            cin >> b;
            b = find(b);

            if (a != b)
            {
                merge(a, b);
            }
        }
    }

    REP(i, 1, n + 1)
    {
        int par = find(i);
        cout << abs(arr[par]) << " ";
    }

    return 0;
}