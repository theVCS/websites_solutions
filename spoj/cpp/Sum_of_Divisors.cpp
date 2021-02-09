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

ll binExp(ll a, ll pow)
{
    ll res = 1;

    while (pow)
    {
        if (pow & 1)
        {
            res = (res * a);
        }
        a = (a * a);
        pow >>= 1;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n, p, res = 1;

    cin >> t;

    while (t--)
    {
        cin >> n >> p;
        res *= ((binExp(n, p + 1) - 1) / (n - 1));
    }

    cout << res;

    return 0;
}