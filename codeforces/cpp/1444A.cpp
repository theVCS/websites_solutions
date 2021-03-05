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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

void solve()
{
    ll p, q;

    cin >> p >> q;

    if (p % q != 0)
    {
        cout << p << endl;
        return;
    }

    vector<ll> div;
    div.push_back(q);

    for (ll i = 2; i * i <= q; i++)
    {
        if (q % i == 0)
        {
            div.push_back(i);

            if (i * i != q)
                div.push_back(q / i);
        }
    }

    ll res = 1;

    for (ll d : div)
    {
        ll dum = p;

        while (dum % d == 0)
        {
            dum /= d;
         
            if (dum % q != 0)
            {
                res = max(res, dum);
                break;
            }
        }
    }

    cout << res << endl;
    return;
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