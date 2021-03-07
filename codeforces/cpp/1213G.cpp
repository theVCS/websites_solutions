#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200011
#define all(x) (x).begin(), (x).end()
#define endl "\n"

//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct edge
{
    int u, v;
    int weight;
};

struct query
{
    int index;
    int weight;
};

bool cmp1(edge a, edge b)
{
    return (a.weight < b.weight);
}

bool cmp2(query a, query b)
{
    return (a.weight < b.weight);
}

vector<edge> arr;
vector<query> que;
int parent[maxN];
ll ans[maxN], res;

int find(int a)
{
    if (parent[a] < 0)
        return a;
    else
        return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    if (parent[a] > parent[b])
        swap(a, b);

    ll size1 = abs(parent[a]);
    ll size2 = abs(parent[b]);

    res -= (size1 * (size1 - 1) / 2) + (size2 * (size2 - 1) / 2);
    res += (size1 + size2) * (size1 + size2 - 1) / 2;
    parent[a] += parent[b];
    parent[b] = a;
}

void solve()
{
    int n, m;

    cin >> n >> m;

    REP(i, 0, n - 1)
    {
        edge e;
        cin >> e.u >> e.v >> e.weight;
        arr.push_back(e);
        parent[i] = -1;
    }

    parent[n - 1] = parent[n] = -1;

    sort(all(arr), cmp1);

    REP(i, 0, m)
    {
        query q;
        q.index = i;
        cin >> q.weight;
        que.push_back(q);
    }

    sort(all(que), cmp2);

    int edin = 0;

    for (query q : que)
    {
        int mxWei = q.weight;

        while (edin <= n - 2 && arr[edin].weight <= mxWei)
        {
            int a = find(arr[edin].u);
            int b = find(arr[edin].v);
            edin++;

            if (a == b)
                continue;

            merge(a, b);
        }

        ans[q.index] = res;
    }

    REP(i, 0, m)
    cout << ans[i] << " ";
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