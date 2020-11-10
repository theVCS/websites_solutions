#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
vector<int> arr[maxN];
bool vis[maxN];
int n, indegree[maxN];
int inD1, inD2, inDV;

void dfs(int node)
{
    vis[node] = true;

    if (arr[node].size() == 1)
    {
        inD1++;
    }
    else if (arr[node].size() == 2)
    {
        inD2++;
    }
    else if (arr[node].size() == n - 1)
    {
        inDV++;
    }

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

    int m, a, b;
    bool isBus = false, isRing = false, isStar = false;

    cin >> n >> m;

    REP(i, 0, m)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1);

    // checking for edges and vertices
    if (m == n - 1 && inD1 == 2 && inD2 == n - 2)
    {
        isBus = true;
    }

    if (n == m && inD2 == n)
    {
        isRing = true;
    }

    if (m == n - 1 && inD1 == n - 1 && inDV == 1)
    {
        isStar = true;
    }

    if (isBus)
    {
        cout << "bus topology";
    }
    else if (isRing)
    {
        cout << "ring topology";
    }
    else if (isStar)
    {
        cout << "star topology";
    }
    else
    {
        cout << "unknown topology";
    }

    return 0;
}