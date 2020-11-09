#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
int arr[maxN];

int find(int a)
{
    while (arr[a] > 0)
    {
        a = arr[a];
    }
    return a;
}

void myunion(int a, int b)
{
    arr[a] += arr[b];
    arr[b] = a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    ll res = 1;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        arr[i] = -1;
    }

    REP(i, 0, m)
    {
        cin >> a >> b;
        a = find(a), b = find(b);

        if (a != b)
            myunion(a, b);
    }

    REP(i, 1, n + 1)
    {
        if (arr[i] < 0)
        {
            res = (res * arr[i] * -1) % mod;
        }
    }

    cout << res;

    return 0;
}