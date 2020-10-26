#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> arr[2001];
vector<bool> vis(2001);
vector<int> gen(2001);

bool dfs(int n, int g)
{
    vis[n] = true;
    gen[n] = g;

    for (int P : arr[n])
    {
        if (!vis[P])
        {
            if (dfs(P, g ^ 1) == false)
            {
                return false;
            }
        }
        else
        {
            if (gen[P] == gen[n])
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m, a, b, cnt = 1;
    bool check;

    cin >> t;

    while (t--)
    {
        gen.clear();
        check = true;

        for (int i = 0; i < 2001; i++)
        {
            arr[i].clear();
            vis[i] = false;
        }

        cin >> n >> m;

        while (m--)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, 1) == false)
                {
                    check = false;
                    cout << "Scenario #" << cnt << ":" << endl;
                    cout << "Suspicious bugs found!" << endl;
                    break;
                }
            }
        }

        if (check)
        {
            cout << "Scenario #" << cnt << ":" << endl;
            cout << "No suspicious bugs found!" << endl;
        }

        cnt++;
    }

    return 0;
}