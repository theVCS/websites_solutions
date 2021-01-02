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

vector<int> arr[maxN];
bool vis[maxN];
map<pair<int, int>, bool> bridges;
int intime[maxN], low[maxN], timer;
map<int, int> counter, totalCounter;

// finding bridges using Tarjan's Algo
void dfs(int node, int par = -1)
{
    vis[node] = true;
    intime[node] = low[node] = ++timer;

    for (int child : arr[node])
    {
        if (child == par)
        {
            continue;
        }
        else if (vis[child])
        {
            low[node] = min(low[node], intime[child]);
        }
        else
        {
            dfs(child, node);
            low[node] = min(low[node], low[child]);

            if (intime[node] < low[child])
            {
                bridges[{node, child}] = true;
            }
        }
    }
}

// applying kruskal's algo
struct edge
{
    int a, b, w;
};
edge edr[maxN], _edr[maxN];

bool cmp(edge a, edge b)
{
    if (a.w < b.w)
    {
        return true;
    }
    return false;
}

vector<int> par(maxN, -1);

int find(int a)
{
    if (par[a] < 0)
    {
        return a;
    }
    return par[a] = find(par[a]);
}

void merge(int a, int b)
{
    if (par[a] > par[b])
    {
        swap(a, b);
    }
    par[a] += par[b];
    par[b] = a;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, w;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b >> w;
        arr[a].push_back(b);
        arr[b].push_back(a);
        edr[i].a = a, _edr[i].a = a;
        edr[i].b = b, _edr[i].b = b;
        edr[i].w = w, _edr[i].w = w;
    }

    dfs(1);

    sort(edr, edr + m, cmp);

    REP(i, 0, m)
    {
        a = find(edr[i].a);
        b = find(edr[i].b);
        totalCounter[edr[i].w]++;

        if (a != b)
        {
            merge(a, b);
            counter[edr[i].w]++;
        }
    }

    REP(i, 0, m)
    {
        if (bridges[{_edr[i].a, _edr[i].b}] || bridges[{_edr[i].b, _edr[i].a}] || counter[_edr[i].w] == totalCounter[_edr[i].w])
        {
            cout << "any" << endl;
        }
        else if (counter[_edr[i].w] && counter[_edr[i].w] < totalCounter[_edr[i].w])
        {
            cout << "at least one" << endl;
        }
        else
        {
            cout << "none" << endl;
        }
    }

    return 0;
}