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

void pythagoreanTriplets(ll limit)
{

    ll a, b, c = 0;
    ll n = 1;
    ll cnt = 0;

    while (c < limit)
    {
        a = 2 * n + 1;
        b = 2 * (n + 1) * n;
        c = 2 * n * n + 2 * n + 1;

        if (c > limit)
            break;

        n++;
        cnt++;
    }

    cout << cnt << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        pythagoreanTriplets(n);
    }

    return 0;
}