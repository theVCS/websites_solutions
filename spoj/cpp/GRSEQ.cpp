#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, -1, 0, 1};
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n, dum, sum;

    cin >> t;

    while (t--)
    {
        sum = 0;
        cin >> n;

        while (n--)
        {
            cin >> dum;
            sum += dum;
        }

        if (sum % 2)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            cout << "POSSIBLE" << endl;
        }
    }

    return 0;
}