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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

map<int, bool> isSpecial;
struct edge
{
    int a, b;
    ll w;
};
edge e[maxN];

bool cmp(edge a, edge b)
{
    if (a.w < b.w)
    {
        return true;
    }
    return false;
}

vector<int> parent(maxN, -1);

int find(int node)
{
    if (parent[node] == -1)
    {
        return node;
    }
    return parent[node] = find(parent[node]);
}

void merge(int a, int b)
{
    if (parent[a] > parent[b])
    {
        swap(a, b);
    }
    parent[a] += parent[b];
    parent[b] = a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, a, b, w;

    cin >> n >> m >> k;

    REP(i, 0, k)
    {
        cin >> a;
        isSpecial[a] = true;
    }

    REP(i, 0, m)
    {
        cin >> e[i].a >> e[i].b >> e[i].w;
    }

    sort(e, e + m, cmp);

    ll ans = 0;
    int par1, par2;

    for (int i = 0; i < m; i++)
    {
        par1 = find(e[i].a), par2 = find(e[i].b);

        cout << par1 << " " << par2 << endl;

        if (par1 != par2)
        {
            merge(par1, par2);

            // if (isSpecial[par1] && isSpecial[par2])
            // {
            //     ans = max(ans, e[i].w);
            //     isSpecial[par1] |= isSpecial[par2];
            // }
        }
    }

    REP(i, 0, k)
    cout << ans << " ";

    return 0;
}