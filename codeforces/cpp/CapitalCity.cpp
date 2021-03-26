#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pil pair<int, ll>
#define pli pair<ll, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
#define INF 0x3f3f3f3f
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

vector<pil> graph[maxN];
bool vis[maxN];
vector<pil> strongGraph[maxN];

// creating directed graph
void dfs0(int node, int par = -1)
{
    vis[node] = true;

    for (pil child : graph[node])
    {
        if (child.first == par)
            continue;
        else if (vis[child.first])
        {
            strongGraph[node].push_back(child);
        }
        else
        {
            dfs0(child.first, node);
            strongGraph[node].push_back(child);
        }
    }
}

// labelling SCCs
bool onStack[maxN];
int label[maxN], intime[maxN], low[maxN], timer, SCC;
stack<int> st;
vector<int> labelSet[maxN];

void dfs1(int node)
{
    vis[node] = true;
    intime[node] = low[node] = ++timer;
    onStack[node] = true;
    st.push(node);

    for (pil child : strongGraph[node])
    {
        if (vis[child.first] && onStack[child.first])
        {
            low[node] = min(low[node], intime[child.first]);
        }
        else if (!vis[child.first])
        {
            dfs1(child.first);

            if (onStack[child.first])
            {
                low[node] = min(low[node], low[child.first]);
            }
        }
    }

    if (intime[node] == low[node])
    {
        SCC++;

        while (true)
        {
            int ut = st.top();
            st.pop();
            onStack[ut] = false;

            label[ut] = SCC;
            labelSet[SCC].push_back(node);

            if (ut == node)
            {
                break;
            }
        }
    }
}

// forming tree from strongly connected graph
vector<pil> tree[maxN];
void treeBuild(int n)
{
    REP(node, 1, n + 1)
    {
        for (pil child : strongGraph[node])
        {
            if (label[node] != label[child.first])
            {
                tree[label[node]].push_back({label[child.first], child.second});
                tree[label[child.first]].push_back({label[node], child.second});
            }
        }
    }
}

ll dist[maxN];
void dfs(int node = 1, int par = -1)
{
    bool leaf = true;
    ll d = 0;
    for (pil child : tree[node])
    {
        if (child.first == par)
            continue;
        dfs(child.first, node);
        d = max(dist[child.first] + child.second, d);
        leaf = false;
    }

    if (leaf)
        dist[node] = 0;
    else
        dist[node] = d;
}

void solve()
{
    int n, m, a, b;
    ll c;

    cin >> n >> m;

    SCC = 0;
    timer = 0;
    REP(i, 1, n + 1)
    {
        graph[i].clear();
        strongGraph[i].clear();
        labelSet[i].clear();
        tree[i].clear();
        vis[i] = false;
    }

    REP(i, 0, m)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    // directed grp formed
    dfs0(1);

    REP(i, 1, n + 1)
    vis[i] = false;

    // strongly component found
    REP(i, 1, n + 1)
    if (vis[i] == false) dfs1(i);

    // tree built
    treeBuild(n);

    ll dis = __LONG_LONG_MAX__;
    int nodeX = 0;

    REP(i, 1, SCC + 1)
    {
        dfs(i);

        if (dis > dist[i])
        {
            dis = dist[i];
            nodeX = i;
        }
    }

    cout << labelSet[nodeX][0] << " " << dis << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}