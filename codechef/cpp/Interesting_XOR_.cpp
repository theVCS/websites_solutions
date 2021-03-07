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
    ll n;

    cin >> n;

    vector<int> setBit;

    int i = 0;

    while (true)
    {
        ll shb = 1LL << i;

        if (n < shb)
            break;

        if (shb & n)
            setBit.push_back(1);
        else
            setBit.push_back(0);

        i++;
    }

    // for (int bit : setBit)
    //     cout << bit << " ";
    // cout << endl;

    ll res1 = 0, res2 = 0;

    i = 0;

    for (i = 0; i < setBit.size(); i++)
    {
        if (setBit[i])
            break;

        res1 += 1LL << i;
        res2 = res1;
    }

    for (; i < setBit.size() - 1; i++)
    {
        if (setBit[i])
        {
            res2 += 1LL << i;
        }
        else
        {
            res1 += 1LL << i;
            res2 += 1LL << i;
        }
    }

    res1 += 1LL << i;

    cout << res1 * res2 << endl;
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