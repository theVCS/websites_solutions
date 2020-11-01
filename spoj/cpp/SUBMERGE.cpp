#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 10001
vector<int> arr[maxN];
set<int> ap;
int timer, intime[maxN], low[maxN];
bool vis[maxN];

void dfs(int node, int par = -1)
{
    vis[node] = true;
    intime[node] = low[node] = timer++;
    int children = 0;

    for (int child : arr[node])
    {
        if (child == par)
        {
            continue;
        }
        else if (vis[child])
        {
            low[node] = min(low[node], intime[child]);
        }
        else
        {
            dfs(child, node);
            low[node] = min(low[node], low[child]);

            if (low[child] >= intime[node] && par != -1)
            {
                ap.insert(node);
            }
            children++;
        }
    }

    if (par == -1 && children > 1)
    {
        ap.insert(node);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, e, a, b;

    while (true)
    {
        cin >> n >> e;

        if (n == 0)
        {
            break;
        }

        timer = 0;
        ap.clear();

        for (int i = 0; i < maxN; i++)
        {
            arr[i].clear();
            vis[i] = false;
        }

        while (e--)
        {
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }

        dfs(1);
        cout << ap.size() << endl;
    }

    return 0;
}