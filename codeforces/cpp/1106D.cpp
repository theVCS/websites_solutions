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
string s[maxN];
bool vis[maxN];
int n;

bool isEqui(string a, string b)
{
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            if (a[i] == b[j])
            {
                return true;
            }
        }
    }
    return false;
}

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
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> s[i];
    }

    REP(i, 1, n + 1)
    {
        REP(j, i + 1, n + 1)
        {
            if (isEqui(s[i], s[j]))
            {
                arr[i].push_back(j);
                arr[j].push_back(i);
                break;
            }
        }
    }

    int cc = 0;

    REP(i, 1, n + 1)
    {
        if (!vis[i])
        {
            dfs(i);
            cc++;
        }
    }

    cout << cc;

    return 0;
}