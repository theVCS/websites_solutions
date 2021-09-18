#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define maxN 100101

int n;
vector<int> arr[maxN];
int intime[maxN], outime[maxN], timer, ft[2 * maxN];
int parent[maxN][17], level[maxN];

void dfs(int node = 1, int par = -1, int l = 0)
{
    intime[node] = ++timer;
    level[node] = l;
    parent[node][0] = par;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        dfs(child, node, l + 1);
    }

    outime[node] = ++timer;
}

void preprocess()
{
    dfs();

    for (int j = 1; j < 17; j++)
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

void update(int index, ll val)
{
    while (index <= 2 * n)
    {
        ft[index] += val;
        index += (index & -1 * index);
    }
}

ll query(int index)
{
    ll sum = 0;

    while (index)
    {
        sum += ft[index];
        index -= (index & -1 * index);
    }

    return sum;
}

int main()
{
    freopen("disconnect.in", "r", stdin);
    freopen("disconnect.out", "w", stdout);

    ll a, b, code, m;

    cin >> n >> m;

    REP(i, 1, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    preprocess();

    ll v = 0;

    while (m--)
    {
        cin >> code >> a >> b;

        a = (a ^ v);
        b = (b ^ v);
        
        int A = a, B = b;

        if (code == 1)
        {
            if (level[a] < level[b])
                swap(a, b);
            update(intime[a], 1), update(outime[a] + 1, -1);
        }
        else
        {

            if (intime[a] > intime[b])
                swap(a, b);
            int lca = LCA(a, b);
            int res = 0;

            if (lca == a)
            {
                res = query(intime[b]) - query(intime[a]);
            }
            else
            {
                res = query(intime[b]) - query(outime[a] - 1);
            }

            if (res == 0)
            {
                cout << "YES" << endl;
                v = A;
            }
            else
            {
                cout << "NO" << endl;
                v = B;
            }
        }
    }

    return 0;
}