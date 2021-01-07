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

vector<int> arr[maxN];
int parent[maxN][17], level[maxN];
int minP, maxP, intime[maxN], outime[maxN], timer, FT[2 * maxN];
map<pii, int> length;

void dfs(int node = 1, int par = -1, int lev = 0)
{
    parent[node][0] = par;
    level[node] = lev;
    intime[node] = ++timer;
    FT[timer] = node;

    for (int child : arr[node])
    {
        if (child != par)
        {
            dfs(child, node, lev + 1);
        }
    }
    outime[node] = ++timer;
    FT[timer] = node;
}

void init(int n)
{
    dfs();

    for (int j = 1; j < 17; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] == -1)
            {
                parent[i][j] = -1;
            }
            else
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
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
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    if (a == b)
    {
        return a;
    }

    for (int i = 16; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b, c;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b >> c;
        arr[a].push_back(b);
        arr[b].push_back(a);
        length[{a, b}] = c;
        length[{b, a}] = c;
    }

    init(n);

    int q, lca;

    cin >> q;

    while (q--)
    {
        cin >> a >> b;

        if (intime[a] > intime[b])
        {
            swap(a, b);
        }

        lca = LCA(a, b);

        map<int, int> path;

        if (lca == a)
        {
            for (int i = intime[a]; i <= intime[b]; i++)
            {
                path[FT[i]]++;
            }
        }
        else
        {
            for (int i = outime[a]; i <= intime[b]; i++)
            {
                path[FT[i]]++;
            }
        }

        for(auto e: path)
        {
            if (e.second == 1)
            {
                
            }
            
        }
    }

    return 0;
}