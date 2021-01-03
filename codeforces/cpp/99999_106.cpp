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
    g = gcd(abs(a), abs(b), x, y);

    if (c % g)
    {
        return false;
    }
    x *= (c / g) * (a / abs(a));
    y *= (c / g) * (b / abs(b));
    return true;
}

void shiftSol(ll a, ll b, ll c, ll &x, ll &y, ll cnt)
{
    x += cnt * b;
    y -= cnt * a;
}

ll findAllSol(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
{
    ll x, y, g;

    if (!findAnySol(a, b, c, x, y, g))
    {
        return 0;
    }

    a /= g;
    b /= g;

    ll sign_a = a > 0 ? 1 : -1;
    ll sign_b = b > 0 ? 1 : -1;

    shiftSol(a, b, c, x, y, (minx - x) / b);
    if (x < minx)
    {
        shiftSol(a, b, c, x, y, sign_b);
    }
    if (x > maxx)
    {
        return 0;
    }
    ll lx1 = x;

    shiftSol(a, b, c, x, y, (maxx - x) / b);
    if (x > maxx)
    {
        shiftSol(a, b, c, x, y, -1 * sign_b);
    }
    ll rx1 = x;

    shiftSol(a, b, c, x, y, (y - miny) / a);
    if (y < miny)
    {
        shiftSol(a, b, c, x, y, -1 * sign_a);
    }
    if (y > maxy)
    {
        return 0;
    }
    ll lx2 = x;

    shiftSol(a, b, c, x, y, (y - maxy) / a);
    if (y > maxy)
    {
        shiftSol(a, b, c, x, y, sign_a);
    }
    ll rx2 = x;

    if (lx2 > rx2)
    {
        swap(lx2, rx2);
    }

    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if (lx > rx)
    {
        return 0;
    }
    return ((rx - lx) / abs(b) + 1);
}

ll solve(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy)
{
    if (a == 0 && b == 0)
    {
        if (c == 0)
        {
            return (maxx - minx + 1) * (maxy - miny + 1);
        }
        else
        {
            return 0;
        }
    }

    if (a == 0)
    {
        if (c % b == 0 && miny <= c / b && maxy >= c / b)
        {
            return (maxx - minx + 1);
        }
        return 0;
    }

    if (b == 0)
    {
        if (c % a == 0 && minx <= c / a && maxx >= c / a)
        {
            return (maxy - miny + 1);
        }
    }

    return findAllSol(a, b, c, minx, maxx, miny, maxy);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c, minx, maxx, miny, maxy;

    cin >> a >> b >> c;
    cin >> minx >> maxx;
    cin >> miny >> maxy;

    cout << solve(a, b, -1 * c, minx, maxx, miny, maxy);

    return 0;
}