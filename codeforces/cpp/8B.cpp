#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int arr[205][205], sx = 101, sy = 101, ex, ey;
int dist[205][205];
bool vis[205][205];

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > 201 || y > 201 || !arr[x][y] || vis[x][y])
    {
        return false;
    }
    return true;
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (isValid(x + dx[i], y + dy[i]))
            {
                vis[x + dx[i]][y + dy[i]] = true;
                dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
                q.push({x + dx[i], y + dy[i]});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int curX = 101, curY = 101;
    string s;

    arr[curX][curY] = true;

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'L')
        {
            curY -= 1;
        }
        if (s[i] == 'R')
        {
            curY += 1;
        }
        if (s[i] == 'U')
        {
            curX -= 1;
        }
        if (s[i] == 'D')
        {
            curX += 1;
        }

        arr[curX][curY] = true;
    }

    ex = curX;
    ey = curY;

    bfs();

    if (dist[ex][ey] == s.size())
    {
        cout << "OK";
    }
    else
    {
        cout << "BUG";
    }

    return 0;
}