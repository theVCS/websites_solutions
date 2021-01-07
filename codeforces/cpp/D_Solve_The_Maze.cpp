#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

char arr[51][51];
bool vis[51][51];
int n, m, gb, bb;

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m || vis[x][y] || arr[x][y] == '#')
    {
        return false;
    }
    return true;
}

bool isReplaceble(int x, int y)
{
    if (arr[x][y] == '.')
    {
        return true;
    }
    return false;
}

void replaceempty(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        if (isReplaceble(x + dx[i], y + dy[i]))
        {
            arr[x + dx[i]][y + dy[i]] = '#';
        }
    }
}

int dfs(int x, int y)
{
    vis[x][y] = true;

    if (arr[x][y] == 'B')
    {
        bb++;
    }
    else if (arr[x][y] == 'G')
    {
        gb++;
    }

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, goodB;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        vector<pii> badP;
        goodB = 0;

        REP(i, 1, n + 1)
        {
            REP(j, 1, m + 1)
            {
                cin >> arr[i][j];

                vis[i][j] = false;

                if (arr[i][j] == 'B')
                {
                    badP.push_back({i, j});
                }
                if (arr[i][j] == 'G')
                {
                    goodB++;
                }
            }
        }

        for (pii e : badP)
        {
            replaceempty(e.first, e.second);
        }

        gb = bb = 0;

        dfs(n, m);

        if ((bb == 0 && gb == goodB) || goodB == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}