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

vector<int> arr[maxN], universities;
int parent[maxN][20], intime[maxN], level[maxN], timer;

void dfs(int node = 1, int par = -1, int l = 0)
{
    intime[node] = timer++;
    level[node] = l;
    parent[node][0] = par;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        dfs(child, node, l + 1);
    }
}

void init(int n)
{
    dfs();

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

int dist(int a, int b)
{
    return level[a] + level[b] - 2 * level[LCA(a, b)];
}

bool cmp(int a, int b)
{
    return intime[a] < intime[b];
}

void solve()
{
    int n, q, a, b;

    cin >> n >> q;

    REP(i, 0, 2 * q)
    {
        cin >> a;
        universities.push_back(a);
    }

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    init(n);

    sort(all(universities), cmp);

    // for(int e: universities)cout << e << " ";

    int i = 0, j = 2 * q - 1, res = 0;

    while (i < j)
    {
        res += dist(universities[i], universities[j]);
        i++;
        j--;
    }
    cout << res;
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