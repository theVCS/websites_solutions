#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int r1, c1, r2, c2;
bool vis[9][9];
int dist[9][9];

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > 8 || y > 8)
    {
        return false;
    }

    if (vis[x][y])
    {
        return false;
    }

    return true;
}

int rookmoves()
{
    if (r1 == r2 || c1 == c2)
    {
        return 1;
    }
    return 2;
}

int bishopmoves()
{
    int c = 1;
    int board[9][9];

    REP(i, 1, 9)
    {
        REP(j, 1, 9)
        {
            board[i][j] = c;
            c ^= 1;
        }
        c ^= 1;
    }

    if (board[r1][c1] == board[r2][c2])
    {
        if (abs(r1 - r2) == abs(c1 - c2))
        {
            return 1;
        }

        return 2;
    }

    return 0;
}

int kingmoves()
{
    int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
    int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};

    queue<pair<int, int>> q;
    q.push({r1, c1});
    vis[r1][c1] = 0;
    dist[r1][c1] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int currx = x + dx[i];
            int curry = y + dy[i];

            if (isValid(currx, curry))
            {
                vis[currx][curry] = true;
                dist[currx][curry] = dist[x][y] + 1;
                q.push({currx, curry});

                if (currx == r2 && curry == c2)
                {
                    return dist[r2][c2];
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r1 >> c1 >> r2 >> c2;
    cout<<rookmoves()<<" ";
    cout << bishopmoves()<<" ";
    cout << kingmoves();

    return 0;
}