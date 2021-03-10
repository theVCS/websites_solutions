#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
vector<int> red;
vector<int> blue;
int intime[maxN], outime[maxN], timer;
int parent[maxN][20];
int level[maxN];

void dfs(int node, int par = -1, int l = 0)
{
    intime[node] = ++timer;
    parent[node][0] = par;
    level[node] = l;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        dfs(child, node, l + 1);
    }

    outime[node] = ++timer;
}

void init(int n)
{
    dfs(1);

    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] == -1)
                parent[i][j] = -1;
            else
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int LCA(int a, int b)
{
    if (level[a] < level[b])
        swap(a, b);

    int d = level[a] - level[b];

    while (d)
    {
        int i = log2(d);
        a = parent[a][i];
        d -= 1 << i;
    }

    if (a == b)
        return a;

    for (int i = 19; i >= 0; i--)
    {
        if (parent[a][i] != -1 && parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

bool check(int lca, vector<int> col)
{
    for (int child : col)
    {
        if (intime[child] >= intime[lca] && outime[child] <= outime[lca])
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    int n, a, b;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    init(n);

    int q;
    cin >> q;

    while (q--)
    {
        int rn, bn, dum;
        cin >> rn >> bn;
        red.clear(), blue.clear();

        int low = 0, high = 0;

        REP(i, 0, rn)
        {
            cin >> dum;
            red.push_back(dum);

            if (low == 0 || intime[low] > intime[dum])
                low = dum;
            if (high == 0 || intime[high] < intime[dum])
                high = dum;
        }

        int lca1 = LCA(low, high);

        low = 0, high = 0;

        REP(i, 0, bn)
        {
            cin >> dum;
            blue.push_back(dum);

            if (low == 0 || intime[low] > intime[dum])
                low = dum;
            if (high == 0 || intime[high] < intime[dum])
                high = dum;
        }

        int lca2 = LCA(low, high);

        if (check(lca1, blue) || check(lca2, red))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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