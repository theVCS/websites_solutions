#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];

void dfs(int node)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    vector<int> res;

    cin >> n >> m;

    REP(I, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    REP(i, 1, n + 1)
    {
        if (vis[i] == false)
            dfs(i), res.push_back(i);
    }

    if (res.size() > 1)
    {
        cout << res.size() - 1 << endl;
        for (int i = 1; i < res.size(); i++)
        {
            cout << res[i] << " " << res[i - 1] << endl;
        }
    }
    else
        cout << 0;

    return 0;
}