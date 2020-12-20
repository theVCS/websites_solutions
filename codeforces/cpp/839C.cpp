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
int n;
bool vis[maxN];
double res;

void dfs(int node = 1, int len = 0, double prob = 1)
{
    vis[node] = true;

    if (arr[node].size() == 1 && vis[arr[node][0]])
    {
        res = res + prob * len;
    }
    else if (node == 1)
    {
        prob = prob / arr[node].size();
    }

    else
    {
        prob = prob / (arr[node].size() - 1);
    }

    for (int child : arr[node])
    {
        if (!vis[child])
        {
            dfs(child, len + 1, prob);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;

    cin >> n;

    REP(i, 0, n - 1)
    {
        cin >> a >> b;

        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs();

    // printf("%.8ld", res);

    printf("%.7f", res);

    return 0;
}