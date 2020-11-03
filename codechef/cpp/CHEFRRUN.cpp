#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001

int n;
bool vis[maxN], cycle;
vector<int> arr[maxN], trans[maxN], order, SS, taste;

void dfs(int node)
{
    vis[node] = true;

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
    order.push_back(node);
}

void dfs1(int node, int cyc)
{
    vis[node] = true;

    for (int child : trans[node])
    {
        if (child == cyc)
        {
            cycle = true;
        }

        if (!vis[child])
        {
            dfs1(child, cyc);
        }
    }

    SS.push_back(node);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, cnt, dum;

    cin >> t;

    while (t--)
    {
        cin >> n;

        // resetting all the values
        cnt = 0;
        order.clear();
        taste.clear();
        cycle = false;

        for (int i = 0; i < n; i++)
        {
            arr[i].clear();
            trans[i].clear();
            vis[i] = false;
            cin >> dum;
            taste.push_back(dum);
        }

        for (int i = 0; i < n; i++)
        {
            int ind = (i + taste[i] + 1) % n;
            arr[i].push_back(ind);
            trans[ind].push_back(i);
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i);
            }
        }

        REP(i, 0, n)
        vis[i] = false;

        for (int i = n - 1; i >= 0; i--)
        {

            if (!vis[order[i]])
            {
                SS.clear();
                dfs1(order[i], order[i]);

                if (cycle)
                {
                    cnt += SS.size();
                    cycle = false;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}