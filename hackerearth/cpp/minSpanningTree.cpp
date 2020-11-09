#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100000
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct edge
{
    int a;
    int b;
    int w;
};
edge arr[100000];
int par[10001];

bool comp(edge a, edge b)
{
    if (a.w < b.w)
    {
        return true;
    }
    return false;
}

int find(int a)
{
    if (par[a] < 0)
    {
        return a;
    }
    else
    {
        return par[a] = find(par[a]);
    }
}

void merge(int a, int b)
{
    if (par[a] < par[b])
    {
        swap(par[a], par[b]);
    }

    par[a] += par[b];
    par[b] = a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, sum = 0;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        par[i] = -1;
    }

    REP(i, 0, m)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].w;
    }

    sort(arr, arr + m, comp);

    REP(i, 0, m)
    {
        a = find(arr[i].a);
        b = find(arr[i].b);

        if (a != b)
        {
            sum += arr[i].w;
            merge(a, b);
        }
    }

    cout << sum;

    return 0;
}