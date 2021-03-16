#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 5001
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<pii> arr[maxN];
int n, par[maxN];

int dfs(int node, int timer)
{
    if (node == 1)
        return 1;

    int res = INT_MIN;

    for (pii child : arr[node])
    {
        if (child.second <= timer)
        {
            int temp = dfs(child.first, timer - child.second);

            if (res < temp)
            {
                res = temp;
                par[child.first] = node;
            }
        }
    }

    return 1 + res;
}

void solve()
{
    int m, t, a, b, c;

    cin >> n >> m >> t;

    REP(i, 0, m)
    {
        cin >> a >> b >> c;
        arr[b].push_back({a, c});
    }

    cout << dfs(n, t) << endl;

    int node = 1;

    while (node)
    {
        cout << node << " ";
        node = par[node];
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