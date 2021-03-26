#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 50001
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

vector<int> arr[maxN];
set<char> ch;
string s;
bool vis[maxN];

void graphBuild(int n)
{
    int i = 1;

    while (i <= (n / 2))
    {
        arr[i].push_back(n - i + 1);
        arr[n - i + 1].push_back(i);
        i++;
    }
}

void dfs(int node)
{
    vis[node] = true;

    if (s[node - 1] != '?')
        ch.insert(s[node - 1]);

    if (ch.size() > 1)
        return;

    for (int child : arr[node])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
}

void solve()
{
    int n, m, a, b;
    ll res = 1;

    cin >> n >> m;

    REP(i, 1, n + 1)
    {
        arr[i].clear();
        vis[i] = false;
    }

    cin >> s;

    graphBuild(n);

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    REP(i, 1, n + 1)
    {
        if (vis[i] == false)
        {
            ch.clear();
    
            dfs(i);

            if (ch.size() > 1)
            {
                cout << 0 << endl;
                return;
            }

            if (ch.size() == 0)
                res = (res * 26) % mod;
        }
    }

    cout << res << endl;
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