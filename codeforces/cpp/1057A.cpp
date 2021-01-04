#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200030
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n;
bool vis[maxN];
vector<int> arr[maxN];
int level[maxN], parent[maxN];
int FT[2 * maxN], intime[maxN], outime[maxN], timer;

void dfs(int node, int par = -1, int lev = 0)
{
    vis[node] = true;
    level[node] = lev;
    parent[node] = par;
    intime[node] = ++timer;
    FT[timer] = node;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child, node, lev + 1);
        }
    }

    outime[node] = ++timer;
    FT[timer] = node;
}

int LCA(int a, int b)
{
    if (level[a] < level[b])
    {
        swap(a, b);
    }

    int d = level[a] - level[b];

    while (d)
    {
        a = parent[a];
        d--;
    }

    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;

    cin >> n;

    REP(i, 2, n + 1)
    {
        cin >> a;
        arr[a].push_back(i);
        arr[i].push_back(a);
    }

    dfs(2);

    a = 1;
    b = n;

    if (intime[a] > intime[b])
    {
        swap(a, b);
    }

    int lca = LCA(a, b);

    map<int, int> check;

    if (lca == a)
    {
        for (int i = intime[a]; i <= intime[b]; i++)
        {
            check[FT[i]]++;
        }
    }
    else
    {
        for (int i = outime[a]; i <= intime[b]; i++)
        {
            check[FT[i]]++;

            if (check[lca] == 0 && parent[FT[i]] == lca)
            {
                check[lca]++;
            }
        }
    }

    for(auto e: check)
    {
        if (e.second == 1)
        {
            cout <<  e.first << " ";
        }
        
    }

    return 0;
}