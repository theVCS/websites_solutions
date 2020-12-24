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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, x, y;

    cin >> t;

    while (t--)
    {
        cin >> x >> y;

        if (x == y)
        {
            if (x % 2)
            {
                cout << 2 * (x - 1) + 1 << endl;
            }
            else
            {
                cout << 2 * x << endl;
            }
        }
        else if (x - y == 2)
        {
            if (x % 2)
            {
                cout << x + y - 1 << endl;
            }
            else
            {
                cout << x + y << endl;
            }
        }
        else
        {
            cout << "No Number" << endl;
        }
    }

    return 0;
}