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
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int col[maxN];

// applying dfs
int intime[maxN], outime[maxN], FT[2 * maxN], timer;
void dfs(int node = 1, int par = -1)
{
    intime[node] = ++timer;
    FT[timer] = node;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        dfs(child, node);
    }

    outime[node] = ++timer;
    FT[timer] = node;
}

// building segment tree
set<int> segTree[maxN * 4];
int lazy[maxN * 4];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        int node = FT[ss];
        segTree[si].insert(col[node]);
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);

        set_union(all(segTree[2 * si]), all(segTree[2 * si + 1]), inserter(segTree[si], segTree[si].begin()));
    }
}

set<int> colCnt;

void query(int si, int ss, int se, int qs, int qe)
{
    if (lazy[si])
    {
        segTree[si].clear();
        segTree[si].insert(lazy[si]);

        if (ss != se)
            lazy[2 * si] = lazy[si], lazy[2 * si + 1] = lazy[si];

        lazy[si] = 0;
    }

    if (ss > qe || se < qs)
        return;

    if (qs <= ss && qe >= se)
    {
        colCnt.insert(all(segTree[si]));
        return;
    }

    int mid = (ss + se) / 2;
    query(2 * si, ss, mid, qs, qe);
    query(2 * si + 1, mid + 1, se, qs, qe);
}

void update(int si, int ss, int se, int qs, int qe, int c)
{
    if (lazy[si])
    {
        segTree[si].clear();
        segTree[si].insert(lazy[si]);

        if (ss != se)
            lazy[2 * si] = lazy[si], lazy[2 * si + 1] = lazy[si];

        lazy[si] = 0;
    }

    if (qs > se || qe < ss)
        return;

    if (qs <= ss && qe >= se)
    {
        segTree[si].clear();
        segTree[si].insert(c);

        if (ss != se)
            lazy[2 * si] = c, lazy[2 * si + 1] = c;

        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe, c);
    update(2 * si + 1, mid + 1, se, qs, qe, c);

    segTree[si].clear();
    set_union(all(segTree[2 * si]), all(segTree[2 * si + 1]), inserter(segTree[si], segTree[si].begin()));
}

void solve()
{
    int n, m, a, b, v, c, code;

    cin >> n >> m;

    REP(i, 1, n + 1)
    // cin >> col[i];
    scanf("%d", col + i);

    REP(i, 0, n - 1)
    {
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        arr[a].push_back(b), arr[b].push_back(a);
    }

    dfs();
    build(1, 1, timer);

    REP(i, 0, m)
    {
        // cin >> code;
        scanf("%d", &code);

        if (code == 1)
        {
            // change color of all the vertex to c in subtree of v
            // cin >> v >> c;
            scanf("%d %d", &v, &c);
            update(1, 1, timer, intime[v], outime[v], c);
        }
        else
        {
            // find number of distinct colors in subtree of v
            // cin >> v;
            scanf("%d", &v);

            int cnt = 0;
            query(1, 1, timer, intime[v], outime[v]);
            // cout << colCnt.size() << endl;
            printf("%d\n", colCnt.size());
            colCnt.clear();
        }
    }
}

int main(int argc, char const *argv[])
{
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

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