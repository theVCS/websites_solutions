#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binexp(ll a, ll pow)
{
    a %= mod;

    ll res = 1;

    while (pow)
    {
        if (pow % 2)
        {
            res = (res * a) % mod;
        }
        pow /= 2;
        a = (a * a) % mod;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    ll n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        if (n < 3)
        {
            cout << n << endl;
        }
        else if (n % 3 == 1)
        {
            cout << (4 * binexp(3, (n - 4) / 3)) % mod << endl;
        }
        else if (n % 3 == 2)
        {
            cout << (2 * binexp(3, (n - 2) / 3)) % mod << endl;
        }
        else
        {
            cout << binexp(3, n / 3) << endl;
        }
    }

    return 0;
}