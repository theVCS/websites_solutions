#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<ll> arr(maxN, -1);
map<string, int> srr;
ll cost[maxN];

int find(int a)
{
    if (arr[a] < 0)
    {
        return a;
    }
    return arr[a] = find(arr[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (cost[a] < cost[b])
        {
            cost[b] = cost[a];
        }
        else
        {
            cost[a] = cost[b];
        }

        if (arr[a] > arr[b])
        {
            swap(a, b);
        }

        arr[a] += arr[b];
        arr[b] = a;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, m, x, a, b;
    string s;
    ll res = 0;

    cin >> n >> k >> m;

    REP(i, 1, n + 1)
    {
        cin >> s;
        srr[s] = i;
    }

    REP(i, 1, n + 1)
    {
        cin >> cost[i];
    }

    REP(i, 0, k)
    {
        cin >> x;

        cin >> a;
        x--;

        REP(i, 0, x)
        {
            cin >> b;
            merge(a, b);
        }
    }

    REP(i, 0, m)
    {
        cin >> s;
        res += cost[find(srr[s])];
    }

    cout << res;

    return 0;
}