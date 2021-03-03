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

vector<int> arr[maxN], trans[maxN], stConGraph[maxN], tree[maxN], order;
bool vis[maxN];
int label[maxN], sccCnt;

void dfsn(int node = 1, int par = -1)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (child == par)
        {
            continue;
        }
        else if (vis[child])
        {
            stConGraph[node].push_back(child);
            trans[child].push_back(node);
        }
        else
        {
            dfsn(child, node);
            stConGraph[node].push_back(child);
            trans[child].push_back(node);
        }
    }
}

void dfs0(int node)
{
    vis[node] = true;

    for (int child : stConGraph[node])
    {
        if (!vis[child])
        {
            dfs0(child);
        }
    }
    order.push_back(node);
}

void dfs1(int node)
{
    vis[node] = true;

    for (int child : trans[node])
    {
        if (!vis[child])
        {
            dfs1(child);
        }
    }

    label[node] = sccCnt;
}

int nodeX = -1, dis = 0;

void dfsTree(int node = 0, int par = -1, int dep = 0)
{
    if (dis < dep)
    {
        dis = dep;
        nodeX = node;
    }

    for (int child : tree[node])
    {
        if (child == par)
            continue;

        dfsTree(child, node, dep + 1);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m, a, b;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        order.clear();
        REP(i, 0, n + 1)
        {
            arr[i].clear();
            vis[i] = false;
            trans[i].clear();
            tree[i].clear();
            stConGraph[i].clear();
        }
        sccCnt = 0;

        while (m--)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        dfsn();
        memset(vis, false, maxN);

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs0(i);
            }
        }

        memset(vis, false, maxN);

        for (int i = n - 1; i > -1; i--)
        {
            if (!vis[order[i]])
            {
                dfs1(order[i]);
                sccCnt++;
            }
        }

        if (sccCnt > 1)
        {
            REP(node, 1, n + 1)
            {
                for (int child : arr[node])
                {
                    if (child > node)
                    {
                        int a = label[child], b = label[node];

                        if (a != b)
                        {
                            tree[a].push_back(b);
                            tree[b].push_back(a);
                        }
                    }
                }
            }

            dis = 0, nodeX = 0;
            dfsTree();
            dfsTree(nodeX);

            cout << sccCnt - 1 - dis << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}