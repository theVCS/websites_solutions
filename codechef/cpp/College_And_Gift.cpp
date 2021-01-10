#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
bool vis[maxN], onStack[maxN];
int intime[maxN], low[maxN], timer;
stack<int> st;
int res = INT_MAX;

void tarjan(int node)
{
    vis[node] = true;
    onStack[node] = true;
    intime[node] = low[node] = ++timer;
    st.push(node);

    for (int child : arr[node])
    {
        if (vis[child] && onStack[child])
        {
            low[node] = min(low[node], intime[child]);
        }
        else if (!vis[child])
        {
            tarjan(child);

            if (onStack[child])
            {
                low[node] = min(low[node], low[child]);
            }
        }
    }

    if (intime[node] == low[node])
    {
        int k = 0;
        while (true)
        {
            int u = st.top();
            onStack[u] = false;
            st.pop();

            k++;

            if (u == node)
            {
                break;
            }
        }

        res = min(res, k);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    ll k;

    cin >> n >> m;
    cin >> k;

    while (m--)
    {
        cin >> a >> b;
        arr[a].push_back(b);
    }

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            tarjan(i);
        }
    }

    if (res == 0)
    {
        res = 1;
    }
    

    cout << k * res;

    return 0;
}