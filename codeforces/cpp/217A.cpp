#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, x[101], y[101];
bool vis[101];

void dfs(int i)
{
    vis[i] = true;

    for (int j = 1; j <= n; j++)
    {
        if (!vis[j] && (x[j] == x[i] || y[j] == y[i]))
        {
            dfs(j);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cc = 0;

    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> x[i] >> y[i];
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            cc++;
            dfs(i);
        }
    }

    cout << cc - 1;

    return 0;
}