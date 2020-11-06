#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 101
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

char arr[maxN][maxN];
// bool vis[maxN][maxN];
int n;
int res;

pair<int, int> pathteller(int x, int y)
{
    if (arr[x][y] == 'R')
    {
        return {x, y + 1};
    }
    else if (arr[x][y] == 'D')
    {
        return {x + 1, y};
    }
    else
    {
        return {x, y - 1};
    }
}

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > n)
    {
        return false;
    }
    return true;
}

void dfs(pair<int, int> &e)
{
    pair<int, int> p;
    p = pathteller(e.first, e.second);

    if (isValid(p.first, p.second))
    {
        e = p;
        dfs(e);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        cin >> n;
        pair<int, int> e;
        res = 0;

        REP(i, 1, n + 1)
        {
            REP(j, 1, n + 1)
            {
                cin >> arr[i][j];
            }
        }

        REP(i, 1, n + 1)
        {
            e.first = 1;
            e.second = i;

            dfs(e);

            // cout << (e.first + e.second) << " ";

            if ((e.first + e.second) % 2 == 0)
            {
                res++;
            }
        }

        cout << res << endl;
    }

    return 0;
}