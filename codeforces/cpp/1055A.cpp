#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int forS[maxN], bacS[maxN], n, ex;
bool flag = true;

bool isValid(int x)
{
    if (x < 1 || x > n)
    {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> ex;

    REP(i, 1, n + 1)
    {
        cin >> forS[i];
    }

    REP(i, 1, n + 1)
    {
        cin >> bacS[i];
    }

    int stop = n;

    if (forS[1])
    {
        REP(i, ex, n + 1)
        {
            if (i == ex && forS[i])
            {
                flag = false;
                break;
            }

            if (i > ex && forS[i] && bacS[i])
            {
                stop = i;
                break;
            }
        }

        if (flag && bacS[stop] && forS[stop])
        {
            if (bacS[ex])
            {
                flag = false;
            }
        }
    }

    if (flag)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }

    return 0;
}