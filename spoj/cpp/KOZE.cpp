#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 251
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int m, n, totalS, totalW;
char arr[maxN][maxN];
bool vis[maxN][maxN];

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > m || y > n || arr[x][y] == '#' || vis[x][y])
    {
        return false;
    }
    return true;
}

pair<int, int> dfs(int x, int y)
{
    pair<int, int> ele(0, 0);
    pair<int, int> dum;
    vis[x][y] = true;

    if (arr[x][y] == 'v')
    {
        ele.first++;
    }

    if (arr[x][y] == 'k')
    {
        ele.second++;
    }

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dum = dfs(x + dx[i], y + dy[i]);
            ele.first += dum.first;
            ele.second += dum.second;
        }
    }
    return ele;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pair<int, int> ele;
    cin >> m >> n;

    REP(i, 1, m + 1)
    {
        REP(j, 1, n + 1)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'k')
            {
                totalS++;
            }

            if (arr[i][j] == 'v')
            {
                totalW++;
            }
        }
    }

    REP(i, 1, m + 1)
    {
        REP(j, 1, n + 1)
        {
            if (isValid(i, j))
            {
                ele = dfs(i, j);

                if (ele.first < ele.second && ele.first && ele.second)
                {
                    totalW -= ele.first;
                }

                if (ele.first >= ele.second && ele.first && ele.second)
                {
                    totalS -= ele.second;
                }
            }
        }
    }

    cout << totalS << " " << totalW;

    return 0;
}