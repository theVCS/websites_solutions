#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

char arr[50][50];

bool isPos(queue<pair<int, int>> q)
{
    int currX, currY, cnt;

    while (!q.empty())
    {
        cnt = 0;
        currX = q.front().first;
        currY = q.front().second;
        q.pop();

        if (arr[currX + 1][currY] == '1')
        {
            cnt++;
        }

        if (arr[currX][currY + 1] == '1')
        {
            cnt++;
        }

        if (cnt == 0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;

    cin >> t;

    while (t--)
    {
        queue<pair<int, int>> q;
        bool flag = false;
        cin >> n;

        REP(i, 0, n)
        {
            REP(j, 0, n)
            {
                cin >> arr[i][j];

                if (i == n - 1 || j == n - 1)
                {
                    if (arr[i][j] == '1')
                    {
                        flag = true;
                    }
                }
                else if (arr[i][j] == '1')
                {
                    q.push({i, j});
                }
            }
        }

        if (flag && isPos(q) || q.size() == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}