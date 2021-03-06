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

ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll d, x1, y1;
    d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

bool findAnySolution(ll a, ll b, ll c, ll &x, ll &y)
{
    ll g = gcd(abs(a), abs(b), x, y);

    if (c % g)
    {
        return false;
    }
    x *= (c / g);
    y *= (c / g);
    return true;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b, c, x, y;

    cin >> a >> b >> c;

    if (findAnySolution(a, b, c, x, y) && x >= 0 && y >= 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}