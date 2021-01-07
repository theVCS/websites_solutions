#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 51
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, m, k;
char arr[maxN][maxN];
bool vis[maxN][maxN];
int cc;
bool isEdge;

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m || vis[x][y] || arr[x][y] == '*')
    {
        return false;
    }
    return true;
}

bool isValid1(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m || arr[x][y] == '*')
    {
        return false;
    }
    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = true;

    if (x == 1 || y == 1 || x == n || y == m)
    {
        isEdge = true;
    }

    for (int i = 0; i < 4; i++)
    {
        if (isValid(x + dx[i], y + dy[i]))
        {
            dfs(x + dx[i], y + dy[i]);
        }
    }

    cc++;
}

void change(int x, int y)
{
    arr[x][y] = '*';
    for (int i = 0; i < 4; i++)
    {
        if (isValid1(x + dx[i], y + dy[i]))
        {
            change(x + dx[i], y + dy[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            cin >> arr[i][j];
        }
    }

    vector<pair<int, pii>> res;
    int cnt = 0;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            if (isValid(i, j))
            {
                isEdge = false;

                cc = 0;

                dfs(i, j);

                if (!isEdge)
                {
                    res.push_back({cc, {i, j}});
                }
            }
        }
    }

    sort(res.begin(), res.end());

    k = res.size() - k;

    for (int i = 0; i < k; i++)
    {
        change(res[i].second.first, res[i].second.second);
        cnt += res[i].first;
    }

    cout << cnt << endl;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }

    // for (pair<int, pii> e : res)
    // {
    //     cout << e.first << "{" << e.second.first << ", " << e.second.second << "}" << endl;
    // }

    return 0;
}