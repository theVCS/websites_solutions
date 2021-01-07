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

ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1, d;
    d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool findAnySol(ll a, ll b, ll c, ll &x, ll &y, ll &g)
{
    g = gcd(a, b, x, y);

    if (c % g)
    {
        return false;
    }
    x *= (c / g);
    y *= (c / g);
    return true;
}

bool findPosSol(ll a, ll b, ll c, ll &x, ll &y)
{
    ll g;

    if (!findAnySol(a, b, c, x, y, g))
    {
        return false;
    }

    if (x < 0 && y < 0)
    {
        return false;
    }
    else if (x < 0)
    {
        while (x < 0)
        {
            x += (b / g);
            y -= (a / g);
        }
    }
    else if (y < 0)
    {
        while (y < 0)
        {
            y += (a / g);
            x -= (b / g);
        }
    }

    if (x >= 0 && y >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c, x, y;

    cin >> c >> a >> b;

    if (findPosSol(a, b, c,  x, y))
    {
        cout << "YES" << endl;
        cout << x << " " << y;
    }
    else
    {
        cout << "NO";
    }

    return 0;
}