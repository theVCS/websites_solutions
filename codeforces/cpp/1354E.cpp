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

struct cc
{
    int v1, v2;
};

vector<int> arr[maxN];
bool vis[maxN];
int col[maxN];
vector<cc> ans;
cc cnt;
int mem[maxN][maxN][2];

bool dfs(int node, int c = 1)
{
    vis[node] = true;
    col[node] = c;

    if (c == 0)
        cnt.v1++;
    else
        cnt.v2++;

    for (int child : arr[node])
    {
        if (vis[child])
        {
            if (col[child] == col[node])
                return false;
        }
        else if (dfs(child, c ^ 1) == false)
            return false;
    }

    return true;
}

bool dp(int n, int sum)
{
    if (sum == 0)
        return true;
    else if (n == 0)
        return false;
    else if (ans[n - 1].v1 <= sum || ans[n - 1].v2 <= sum)
    {
        bool b1 = false;
        bool b2 = false;

        if (ans[n - 1].v1 <= sum)
            mem[n][sum][0] = dp(n - 1, sum - ans[n - 1].v1);
        if (ans[n - 1].v2 <= sum)
            mem[n][sum][1] = dp(n - 1, sum - ans[n - 1].v2);

        if (mem[n][sum][0] || mem[n][sum][1])
            return true;
    }
    else
    {
        return dp(n - 1, sum);
    }
}

void solve()
{
    int n, m, a, b, n1, n2, n3;

    cin >> n >> m;

    cin >> n1 >> n2 >> n3;

    memset(mem, -1, sizeof(mem));

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    REP(i, 1, n + 1)
    if (vis[i] == false)
    {
        cnt.v1 = 0, cnt.v2 = 0;

        if (dfs(i) == false)
        {
            cout << "NO";
            return;
        }

        ans.push_back(cnt);
    }

    if (dp(ans.size(), n2))
        cout << "YES" << endl;
    else
        cout << "No" << endl;
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