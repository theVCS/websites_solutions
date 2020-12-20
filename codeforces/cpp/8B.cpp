#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 205
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool vis[maxN][maxN];
string s;
int totalLen, ptr;

bool dfs(int x = 101, int y = 101)
{
    char c;
    while (ptr <= totalLen)
    {
        if (vis[x][y] || vis[x - 1][y] || vis[x + 1][y] || vis[x][y - 1] || vis[x][y + 1])
        {
            return false;
        }

        vis[x][y] = true;

        c = s[ptr - 1];

        if (c == 'L')
        {
            y -= 1;
        }
        else if (c == 'R')
        {
            y += 1;
        }
        else if (c == 'U')
        {
            x -= 1;
        }
        else
        {
            x += 1;
        }

        ptr++;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    totalLen = s.length();

    if (dfs())
    {
        cout << "OK";
    }
    else
    {
        cout << "BUG";
    }

    return 0;
}