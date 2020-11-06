#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 501
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int r, c;
char arr[maxN][maxN];
bool vis[maxN][maxN], flag = true;
queue<pair<int, int>> q;

bool flagChecker(int x, int y)
{
    if (arr[x][y - 1] == 'S' || arr[x - 1][y] == 'S' || arr[x][y + 1] == 'S' || arr[x + 1][y] == 'S')
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    REP(i, 1, r + 1)
    {
        REP(j, 1, c + 1)
        {
            cin >> arr[i][j];

            if (arr[i][j] == 'W')
            {
                q.push({i, j});
            }
        }
    }

    int count = q.size();
    for (int i = 0; i < count; i++)
    {
        if (flagChecker(q.front().first, q.front().second))
        {
            flag = false;
            break;
        }

        q.pop();
    }

    if (flag)
    {
        cout << "Yes" << endl;

        REP(i, 1, r + 1)
        {
            REP(j, 1, c + 1)
            {
                if (arr[i][j] == '.')
                {
                    cout << "D";
                }
                else
                {
                    cout << arr[i][j];
                }
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No";
    }

    return 0;
}