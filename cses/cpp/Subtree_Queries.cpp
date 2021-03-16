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

vector<int> tree[maxN];
int col[maxN], n;

int intime[maxN], outime[maxN], FT[2 * maxN], timer;
void dfs(int node = 1, int par = -1)
{
    intime[node] = ++timer;
    FT[timer] = node;

    for (int child : tree[node])
    {
        if (child == par)
            continue;
        dfs(child, node);
    }

    outime[node] = ++timer;
    FT[timer] = node;
}

ll segTree[8 * maxN];
void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = col[FT[ss]];
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
    }
}

ll query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
        return segTree[si];

    int mid = (ss + se) / 2;
    return query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe);
}

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si] = col[FT[ss]];
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
        update(2 * si, ss, mid, qi);
    else
        update(2 * si + 1, mid + 1, se, qi);

    segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
}

void solve()
{
    int q, a, b;

    cin >> n >> q;

    REP(i, 1, n + 1)
    {
        cin >> col[i];
    }

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        tree[a].push_back(b), tree[b].push_back(a);
    }

    dfs();
    build(1, 1, timer);

    // cout << segTree[1] << endl;

    int code;

    while (q--)
    {
        cin >> code;

        if (code == 1)
        {
            cin >> a >> b;
            col[a] = b;
            update(1, 1, timer, intime[a]);
            update(1, 1, timer, outime[a]);
        }
        else
        {
            cin >> a;
            cout << query(1, 1, timer, intime[a], outime[a]) / 2 << endl;
        }
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