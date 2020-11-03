#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, -1, 0, 1};
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
queue<pair<int, int>> q;
bool vis[1001][1001];
int cnt;

void marker(int x, int y)
{
    REP(i, 1, 1001)
    {
        vis[x][i] = true;
        vis[i][y] = true;
    }
}

void pro()
{
    int x, y;

    x = q.front().first;
    y = q.front().second;
    q.pop();

    marker(x, y);

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (!vis[x][y])
        {
            cnt++;
        }

        marker(x, y);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y;
    cin >> n;

    while (n--)
    {
        cin >> x >> y;
        q.push({x, y});
    }

    pro();
    
    cout << cnt;

    return 0;
}