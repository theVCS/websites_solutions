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

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1, d;
    d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool findAnySol(int a, int b, int c, int &x, int &y, int &g)
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

bool findPosSol(int a, int b, int c)
{
    int x, y, g;

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

    int a, b, c, x, y, g;

    cin >> a >> b >> c;

    if (findPosSol(a, b, c))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}