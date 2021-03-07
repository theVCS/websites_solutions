#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define all(x) (x).begin(), (x).end()
#define endl "\n"

//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct edge
{
    int a, b;
    ll cost;
};

bool cmp(edge a, edge b)
{
    return a.cost < b.cost;
}

vector<edge> arr;
int parent[maxN], cnt;

int find(int a)
{
    if (parent[a] < 0)
        return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    if (parent[a] > parent[b])
        swap(a, b);

    parent[a] += parent[b];
    parent[b] = a;
    cnt--;
}

void solve()
{
    int n, m;
    ll res = 0;

    cin >> n >> m;

    cnt = n;

    REP(i, 0, n + 1)
    parent[i] = -1;

    REP(i, 0, m)
    {
        edge e;
        cin >> e.a >> e.b >> e.cost;
        arr.push_back(e);
    }

    sort(all(arr), cmp);

    for (edge e : arr)
    {
        int a = find(e.a), b = find(e.b);

        if (a == b)
            continue;

        res += e.cost;
        merge(a, b);
    }

    if (cnt == 1)
    {
        cout << res;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}