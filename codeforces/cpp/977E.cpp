#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];
int cc;
bool vis[maxN];
int e, v;
bool isRing;

void dfs(int node)
{
    vis[node] = true;

    if (arr[node].size() != 2)
    {
        isRing = false;
    }

    for (int child : arr[node])
    {
        ++e;
        if (!vis[child])
        {
            ++v;
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

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {

        if (!vis[i])
        {
            e = 0;
            v = 1;
            isRing = true;

            dfs(i);

            if (isRing && (e == 2 * v) && e > 2)
            {
                cc++;
            }
        }
    }

    cout << cc;

    return 0;
}