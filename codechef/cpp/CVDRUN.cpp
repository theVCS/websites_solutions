#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, -1, 0, 1};
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, k, x, y, currPos;
    bool flag;

    cin >> t;

    while (t--)
    {
        cin >> n >> k >> x >> y;
        currPos = (x + k) % n;
        flag = false;

        if (x == y)
        {
            flag = true;
        }
        else
        {
            while (currPos != x)
            {

                if (currPos == y)
                {
                    flag = true;
                    break;
                }

                currPos = (currPos + k) % n;
            }
        }

        if (flag)
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