#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN];
int cn;

void dfs(int node)
{
    vis[node] = true;
    cn++;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, dum, a, b, lsize = 0;
    vector<int> gov, ccsize;

    cin >> n >> m >> k;

    while (k--)
    {
        cin >> dum;
        gov.push_back(dum);
    }

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int g : gov)
    {
        cn = 0;
        dfs(g);
        ccsize.push_back(cn);
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            cn = 0;
            dfs(i);
            lsize += cn;
        }
    }

    sort(ccsize.begin(), ccsize.end(), greater <>());

    ll res = ((ccsize[0] + lsize) * (ccsize[0] + lsize - 1)) / 2;

    for (int i = 1; i < ccsize.size(); i++)
    {
        res += (ccsize[i] * (ccsize[i] - 1)) / 2;
    }

    cout << res - m;

    return 0;
}