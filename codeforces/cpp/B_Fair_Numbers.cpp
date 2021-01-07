#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#define ll long long int
// #define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll __lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

bool isFair(ll n)
{
    ll k = n, l = 1;

    while (k)
    {
        if (k % 10)
        {
            l = __lcm(l, k % 10);
        }

        k /= 10;
    }

    return n % l ? false : true;
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

        while (!isFair(n))
        {
            n++;
        }
        cout << n << endl;
    }

    return 0;
}