// compile in 8.3 gcc

#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;
#define ll cpp_int
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll pow, ll m)
{
    ll res = 1;

    while (pow)
    {
        if (pow % 2)
        {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        pow /= 2;
    }
    return res;
}

bool isComposite(ll a, ll d, ll s, ll n)
{
    ll res = binExp(a, d, n);

    if (res == 1 || res == n - 1)
    {
        return false;
    }

    for (ll i = 1; i < s; i++)
    {
        res = (res * res) % n;

        if (res == n - 1)
        {
            return false;
        }
    }
    return true;
}

bool millerRabin(ll n)
{
    if (n != 2 && (n < 2 || n % 2 == 0))
    {
        return false;
    }

    ll d = n - 1, s = 0;

    while (d % 2 == 0)
    {
        d /= 2;
        s++;
    }

    for (ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
        {
            return true;
        }

        if (isComposite(a, d, s, n))
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

    int t;
    ll n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        if (millerRabin(n))
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