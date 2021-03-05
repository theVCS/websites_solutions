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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll eleCount(ll n, ll row)
{
    return 2 * (n * row - (row * (row + 1) / 2));
}

ll ele(ll n, ll k)
{
    if (k == n * (n - 1) + 1 || k == 1)
        return 1;

    ll row = ceil(((2.0 * n - 1) - sqrt(4.0 * n * n + 1 - 4.0 * n - 4.0 * k)) / 2);
    ll eleCnt = eleCount(n, row - 1);
    ll col = (k - eleCnt) + 2 * (row - 1);

    if (col & 1)
        return row;
    else
        return (col / 2) + 1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        ll n, l, r;
        cin >> n >> l >> r;

        for (ll i = l; i <= r; i++)
        {
            cout << ele(n, i) << " ";
        }
        cout << endl;
    }

    return 0;
}