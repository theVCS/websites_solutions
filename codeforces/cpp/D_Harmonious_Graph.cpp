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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int maxV, minV;
bool vis[maxN];

void dfs(int node)
{
    vis[node] = true;
    maxV = max(maxV, node);
    minV = min(minV, node);

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

    int n, m, a, b;

    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    vector<pii> vec;

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            maxV = INT_MIN;
            minV = INT_MAX;
            dfs(i);

            vec.push_back({minV, maxV});
        }
    }

    int curr = -1, res = 0;

    for (pii e : vec)
    {
        if (e.first < curr)
        {
            res++;
        }
        curr = max(curr, e.second);
    }
    
    cout << res;

    return 0;
}