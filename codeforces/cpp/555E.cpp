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
#define all(x) (x).begin(), (x).end()
#define endl "\n"

//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int intime[maxN], low[maxN], cc[maxN], timer, cccnt;

void dfs(int node, int par = -1)
{
    vis[node] = true;
    intime[node] = low[node] = timer++;
    cc[node] = cccnt;
    int pcnt = 0;

    for (int child : arr[node])
    {
        if (pcnt == 0 && child == par)
        {
            pcnt++;
            continue;
        }
        else if (vis[child])
        {
            low[node] = min(low[node], intime[child]);
        }
        else
        {
            dfs(child, node);
            low[node] = min(low[node], low[child]);
        }
    }
}

void solve()
{
    int n, m, q, a, b;

    cin >> n >> m >> q;

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    bool flag = true;
    bool firstTime = true;

    while (q--)
    {
        cin >> a >> b;

        if (vis[a] == false)
            dfs(a), cccnt++;

        if (vis[b] == false)
            dfs(b), cccnt++;

        if (firstTime)
        {
            if (cc[a] == cc[b] && low[a] <= low[b])
                continue;
            else
                flag = false;

            firstTime = false;
        }
        else
        {
            if (flag)
            {
                if (cc[a] == cc[b] && low[a] <= low[b])
                    continue;
                else
                {
                    cout << "No";
                    return;
                }
            }
            else
            {
                if (cc[a] == cc[b] && low[a] >= low[b])
                    continue;
                else
                {
                    cout << "No";
                    return;
                }
            }
        }

        if (cc[a] == cc[b] && low[a] <= low[b])
            continue;
        else
        {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}