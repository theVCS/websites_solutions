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

void shiftSol(ll a, ll b, ll c, ll &x, ll &y, ll g, ll cnt)
{
    x += (cnt * b) / g;
    y -= (cnt * a) / g;
}

ll findAllSol(ll a, ll b, ll c, ll &x, ll &y, ll &g)
{
    if (!findAnySol(a, b, c, x, y, g))
    {
        return -1;
    }

    ll sign_a = a > 0 ? 1 : -1;
    ll sign_b = b > 0 ? 1 : -1;

    // shiftSol(a, b, c, x, y, g, (-1 * x * g) / b);
    // if (x < 0)
    // {
    //     shiftSol(a, b, c, x, y, g, sign_b);
    // }

    while (y < 0)
    {
        shiftSol(a, b, c, x, y, g, -1 * sign_a);
    }
}

ll solve(ll a, ll b, ll c, ll x, ll y, ll g)
{
    if (a == 0 || b == 0)
    {
        if (c == 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    if (a == 0)
    {
        if (c % b == 0 && c / b > 0)
        {
            return (c / b);
        }
        return -1;
    }

    if (b == 0)
    {
        if (c % a == 0 && c / a > 0)
        {
            return (c / a);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, a, k, x, y, g;
    bool flag;

    while (true)
    {
        cin >> n >> m >> a >> k;

        if (n == 0 && m == 0 && a == 0 && k == 0)
        {
            break;
        }

        flag = findAnySol(a, -m, n - a - k, x, y, g);

        cout << (m * y + n) << endl;
    }

    return 0;
}