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

    ll n;
    cin >> n;

    while (n)
    {
        ll res = n;

        for (ll i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                res /= i;
                res *= i - 1;

                while (n % i == 0)
                {
                    n /= i;
                }
            }
        }

        if (n > 1)
        {
            res *= n - 1;
            res /= n;
        }

        cout << res << endl;
        cin >> n;
    }

    return 0;
}