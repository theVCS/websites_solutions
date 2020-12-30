#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 3000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN], SCC;
bool vis[maxN], onStack[maxN];
int intime[maxN], low[maxN], timer, cnt, res;
stack<int> st;

void dfs(int node)
{
    vis[node] = true;
    intime[node] = low[node] = ++timer;
    onStack[node] = true;
    st.push(node);

    for (int child : arr[node])
    {
        if (vis[child] && onStack[child])
        {
            low[node] = min(low[node], intime[child]);
        }
        else if (!vis[child])
        {
            dfs(child);

            if (onStack[child])
            {
                low[node] = min(low[node], low[child]);
            }
        }
    }

    if (intime[node] == low[node])
    {
        cnt = 0;
        while (true)
        {
            int u = st.top();
            st.pop();
            cnt++;
            onStack[u] = false;

            if (u == node)
            {
                break;
            }
        }

        if (cnt > 1)
        {
            res += cnt;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    string str;

    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> str;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '-')
            {
                arr[i].push_back((i + 1) % n);
                arr[(i + 1) % n].push_back(i);
            }
            else if (str[i] == '>')
            {
                arr[i].push_back((i + 1) % n);
            }
            else
            {
                arr[(i + 1) % n].push_back(i);
            }
        }

        REP(i, 0, n)
        {
            if (!vis[i])
            {
                dfs(i);
            }
        }

        cout << res << endl;

        REP(i, 0, n)
        {
            arr[i].clear();
            vis[i] = false;
            intime[i] = low[i] = 0;
            timer = 0;
            res = 0;
        }
    }

    return 0;
}