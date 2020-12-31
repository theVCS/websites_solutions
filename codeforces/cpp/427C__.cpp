#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN], SCC;
int intime[maxN], low[maxN], timer;
bool vis[maxN], inStack[maxN];
stack<int> st;
ll mincost, ways = 1, ind, cost[maxN];

void dfs(int node)
{
    vis[node] = true;
    intime[node] = low[node] = ++timer;
    st.push(node);
    inStack[node] = true;

    for (int child : arr[node])
    {
        if (vis[child] && inStack[child])
        {
            low[node] = min(low[node], intime[child]);
        }
        else if (!vis[child])
        {
            dfs(child);

            if (inStack[child])
            {
                low[node] = min(low[child], low[node]);
            }
        }
    }

    if (low[node] == intime[node])
    {
        ll dum = LONG_MAX;
        ll same = 0;
        SCC.clear();
        while (true)
        {
            int u = st.top();
            st.pop();
            SCC.push_back(u);
            inStack[u] = false;

            dum = min(dum, cost[u]);

            if (u == node)
            {
                break;
            }
        }

        for (int e : SCC)
        {
            if (dum == cost[e])
            {
                same++;
            }
        }

        mincost += dum;
        ways = (ways * same) % mod;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;

    cin >> n;

    REP(i, 1, n + 1)
    cin >> cost[i];

    cin >> m;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    cout << mincost << " " << ways;

    return 0;
}