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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    ll a, b, c, r;

    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c >> r;

        if (a > b)
        {
            swap(a, b);
        }

        if (c <= a)
        {
            if (c + r >= b)
            {
                cout << 0 << " ";
            }
            else if (c + r >= a)
            {
                cout << b - (c + r) << " ";
            }
            else
            {
                cout << b - a + 1<< " ";
            }
        }
        else if (c >= b)
        {
            if (c - r <= a)
            {
                cout << 0 << " ";
            }
            else if (c - r > a && c - r <= b)
            {
                cout << c - r - a << " ";
            }
            else
            {
                cout << b - a + 1 << " ";
            }
        }
        else
        {
            cout << c - r - a + b - (c + r) << " ";
        }
    }

    return 0;
}