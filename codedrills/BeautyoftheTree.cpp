#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define INF 1000000000
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

vector<int> arr[maxN];
ll val[maxN];
ll mxVal[maxN];
vector<ll> fun;

void dfs(int node, int par = -1)
{
    ll v = val[node];

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        dfs(child, node);
        v = max(v, mxVal[child]);
    }

    mxVal[node] = v;
}

void dfs1(int node, int par)
{
    vector<ll> childValPre;
    vector<ll> childValSuf;
    vector<ll> chd;

    for (int child : arr[node])
    {
        if (child == par)
            continue;
        childValPre.push_back(mxVal[child]);
        childValSuf.push_back(mxVal[child]);
        chd.push_back(child);
    }

    int sz = childValPre.size();

    if (sz == 0)
        return;

    REP(i, 1, sz)
    childValPre[i] = max(childValPre[i], childValPre[i - 1]);
    for (int i = sz - 2; i >= 0; i--)
        childValSuf[i] = max(childValSuf[i], childValSuf[i + 1]);

    int c_index = 0;

    while (c_index < sz)
    {
        ll leftMax = c_index == 0 ? 0 : childValPre[c_index - 1];
        ll rightMax = c_index == sz - 1 ? 0 : childValSuf[c_index + 1];
        ll rmax = max({leftMax, rightMax, val[node]});
        val[chd[c_index]] = max(rmax, val[chd[c_index]]);

        fun.push_back(abs(rmax - mxVal[chd[c_index]]));

        dfs1(chd[c_index], node);
        c_index++;
    }
}

void solve()
{
    int n, a, b;
    cin >> n;

    REP(i, 0, n + 1)
    {
        arr[i].clear();
    }
    fun.clear();

    REP(i, 0, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    REP(i, 1, n + 1)
    cin >> val[i];

    dfs(1);
    dfs1(1, -1);

    // expedted values
    // for(ll e: fun)cout << e << " ";
    cout << endl;
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