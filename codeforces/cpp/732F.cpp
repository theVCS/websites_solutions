#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 400001
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN], bridge;
bool vis[maxN];
map<int, map<int, int>> isBridge;
int intime[maxN], low[maxN], timer;
vector<int> orientedGraph[maxN];
int sizeConCom[maxN];
vector<int> nodes;
vector<pii> res;
map<int, map<int, int>> isOriented, edgeIntime;

void dfs(int node = 1, int par = -1)
{
    vis[node] = true;
    intime[node] = low[node] = ++timer;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        else if (vis[child])
        {
            low[node] = min(low[node], intime[child]);
            orientedGraph[node].push_back(child);
            orientedGraph[child].push_back(node);
        }
        else
        {
            dfs(child, node);

            low[node] = min(low[node], low[child]);

            if (intime[node] < low[child])
            {
                isBridge[node][child] = 1;
                bridge.push_back(node);
                bridge.push_back(child);
            }
            else
            {
                orientedGraph[node].push_back(child);
                orientedGraph[child].push_back(node);
            }
        }
    }
}

int sizeX;

void dfs0(int node)
{
    sizeX++;
    vis[node] = true;
    nodes.push_back(node);

    for (int child : orientedGraph[node])
    {
        if (vis[child])
            continue;
        dfs0(child);
    }
}

void orientor(int node, int par = -1)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        else if (vis[child])
        {
            if (isOriented[node][child] || isOriented[child][node])
            {
                continue;
            }
            else
            {
                res.push_back({node, child});
                isOriented[node][child] = 1;
            }
        }
        else
        {
            orientor(child, node);

            if (isOriented[node][child] || isOriented[child][node])
            {
                continue;
            }
            else if (isBridge[node][child] || isBridge[child][node])
            {
                res.push_back({child, node});
                isOriented[node][child] = 1;
            }
            else
            {
                isOriented[node][child] = 1;
                res.push_back({node, child});
            }
        }
    }
}

bool cmp(pii a, pii b)
{
    return edgeIntime[a.first][a.second] < edgeIntime[b.first][b.second];
}

void solve()
{
    int n, m, a, b;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
        edgeIntime[a][b] = i;
        edgeIntime[b][a] = i;
    }

    dfs();

    REP(i, 0, n + 1)
    vis[i] = false;

    int mainSize = 0, mainNode = 0;

    for (int node : bridge)
    {
        if (vis[node] == false)
        {
            sizeX = 0;
            nodes.clear();

            dfs0(node);

            if (mainSize < sizeX)
            {
                mainSize = sizeX;
                mainNode = node;
            }

            for (int e : nodes)
                sizeConCom[e] = sizeX;
        }
    }

    memset(vis, false, sizeof(vis));

    cout << mainSize << endl;

    orientor(mainNode);

    sort(all(res), cmp);

    for (pii e : res)
    {
        cout << e.first << " " << e.second << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}