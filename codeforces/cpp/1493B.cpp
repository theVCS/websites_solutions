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
#define endl "\n"

//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int mirror(int i)
{
    if (i == 1 || i == 8 || i == 0)
        return i;
    if (i == 2)
        return 5;
    if (i == 5)
        return 2;

    return -1;
}

bool isValid(int tim, int lim)
{
    int left = tim / 10;
    int right = tim % 10;

    int _r = mirror(left);
    int _l = mirror(right);

    if (_r == -1 || _l == -1 || (_l * 10 + _r) >= lim)
        return false;

    return true;
}

void solve()
{
    int h, m, _h, _m, _ph;
    char c;

    cin >> h >> m;

    cin >> _h >> c >> _m;
    _ph = _h;

    while (isValid(_m, h) == false)
    {
        _m = (_m + 1) % m;

        if (_m == 0)
            _h = (_h + 1) % h;
    }

    while (isValid(_h, m) == false)
    {
        _h = (_h + 1) % h;
    }

    if (_ph != _h)
        _m = 0;

    if ((_h % 10) == _h)
        cout << 0;
    cout << _h;

    cout << c;

    if ((_m % 10) == _m)
        cout << 0;
    cout << _m;

    cout << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}