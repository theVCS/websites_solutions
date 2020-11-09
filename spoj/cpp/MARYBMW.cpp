#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 50001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;
int arr[50001];

struct edge
{
    int a;
    int b;
    ll w;
};
edge obj[100000];

bool comp(edge a, edge b)
{
    if (a.w > b.w)
    {
        return true;
    }
    return false;
}

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
    {
        swap(a, b);
    }

    arr[a] += arr[b];
    arr[b] = a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, m;
    ll res;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        REP(i, 0, m)
        {
            cin >> obj[i].a >> obj[i].b >> obj[i].w;
        }

        sort(obj, obj + m, comp);

        REP(i, 1, n + 1)
        {
            arr[i] = -1;
        }

        res = __LONG_LONG_MAX__;

        REP(i, 0, m)
        {
            int a = find(obj[i].a);
            int b = find(obj[i].b);

            if (a != b)
            {
                merge(a, b);
                res = min(res, obj[i].w);
            }

            if (find(1) == find(n))
            {
                break;
            }
            
        }

        if (find(n) == find(1))
        {
            cout << res << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}