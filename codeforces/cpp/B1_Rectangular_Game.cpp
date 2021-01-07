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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll div(ll n)
{
    if (n % 2 == 0)
    {
        return 2;
    }

    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return i;
        }
    }

    return n;
}

ll isPrime(ll n)
{
    if (n % 2 == 0)
    {
        return false;
    }

    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
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

    ll n, a, b;

    cin >> n;

    ll sum = n, oldb = 0;

    while (n != 1)
    {
        a = div(n);
        b = n / a;

        if (a > b)
        {
            swap(a, b);
        }

        if (a == n || b == n)
        {
            oldb = n;
        }
        

        if (b == oldb)
        {
            swap(a, b);
        }

        n = b;
        sum += n;
        oldb = b;
    }

    // sum += 1;

    cout << sum;

    return 0;
}