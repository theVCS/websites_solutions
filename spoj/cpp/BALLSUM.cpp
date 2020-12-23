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

    ll n, k, gcd;

    cin >> n >> k;

    while (n != -1)
    {
        ll tp = (n * (n - 1)) / 2;
        ll steps = (k - 1) / 2;
        ll tot_ways = steps * (k - steps - 1);

        if (tot_ways == 0)
        {
            cout << 0 << endl;
        }
        else if (tp == tot_ways)
        {
            cout << 1 << endl;
        }
        else
        {
            gcd = __gcd(tp, tot_ways);
            cout << tot_ways / gcd << "/" << tp / gcd << endl;
        }

        cin >> n >> k;
    }

    return 0;
}