#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 10001
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

struct strConCom
{
    int node, label;
} info[maxN];

vector<int> arr[maxN], strCon[maxN];
bool vis[maxN], onStack[maxN];
int intime[maxN], low[maxN], timer, SCC;
stack<int> st;
vector<pii> tree[maxN]; // first element is node (label) and second is the node

void preCom(int node, int par = -1)
{
    vis[node] = true;
    int cntPar = 0;

    for (int child : arr[node])
    {
        if (child == par && cntPar == 0)
        {
            cntPar++;
            continue;
        }
        else if (vis[child])
            strCon[node].push_back(child);
        else
        {
            preCom(child, node);
            strCon[node].push_back(child);
        }
    }
}

void dfs(int node)
{
    vis[node] = true;
    intime[node] = low[node] = ++timer;
    onStack[node] = true;
    st.push(node);

    for (int child : strCon[node])
    {
        if (vis[child] && onStack[child])
        {
            low[node] = min(low[node], intime[child]);
        }
        else if (!vis[child])
        {
            dfs(child);

            if (onStack[child])
            {
                low[node] = min(low[node], low[child]);
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

            info[ut].label = SCC;
            info[ut].node = node;

            if (ut == node)
            {
                break;
            }
        }
    }
}

void treeBuilder(int node = 1, int par = -1)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (vis[child])
            continue;

        treeBuilder(child, node);

        if (info[node].label != info[child].label)
        {
            tree[info[node].label].push_back({info[child].label, info[child].node});
            tree[info[child].label].push_back({info[node].label, info[node].node});
        }
    }
}

pii nodeX;
int dis;

void treeDfs(pii node, int par = -1, int d = 0)
{
    if (d >= dis)
    {
        dis = d;
        nodeX = node;
    }

    for (pii child : tree[node.first])
    {
        if (child.first == par)
            continue;
        treeDfs(child, node.first, d + 1);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ifstream fi("input.txt");
    ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    // int t = 1;

    //cin >> t;

    // while (t--)
    // {
    //     solve();
    // }

    int n, m, a, b;

    fi >> n >> m;

    REP(i, 0, m)
    {
        fi >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    // making graph a strongly connected graph
    preCom(1);

    REP(i, 1, n + 1)
    vis[i] = false;

    // finding connected components and labelling them
    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    REP(i, 1, n + 1)
    vis[i] = false;

    // creating tree from strongly connected components
    treeBuilder(1);

    // applying tree dfs
    treeDfs({info[1].label, info[1].node});
    int nodea = nodeX.second;

    treeDfs(nodeX);
    int nodeb = nodeX.second;

    fo << nodea << " " << nodeb;

    fi.close();
    fo.close();

    return 0;
}