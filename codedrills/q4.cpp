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
// #define endl "\n"
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

struct user
{
    int charger, mobile;
} User[maxN];
map<int, int> charger;
map<int, int> mobile;
vector<int> arr[maxN];
bool vis[maxN];

void dfs(int node)
{
    vis[node] = true;
    charger[User[node].charger]++;
    mobile[User[node].mobile]++;

    for (int child : arr[node])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
}

void solve()
{
    int n, m, x, a, b;

    cin >> n >> m >> x;

    REP(i, 1, n + 1)
    {
        cin >> User[i].mobile >> User[i].charger;
    }

    REP(i, 0, m)
    {
        cin >> a >> b;
        a++, b++;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    int res = 0;

    REP(i, 1, n + 1)
    {
        if (vis[i] == false)
        {
            charger.clear();
            mobile.clear();

            dfs(i);

            for (auto ch : charger)
            {
                res += min(ch.second, mobile[ch.first]);
            }
        }
    }

    cout << n - res << endl;
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

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}