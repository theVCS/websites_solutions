#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 998244353
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define INF 1000000000
// #define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

ll f[maxN];
ll sumF[maxN];

void solve()
{
    int l, r;
    cin >> l >> r;
    cout << (sumF[r] - sumF[l - 1] + mod) % mod << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    REP(i, 2, maxN)
    {
        // finding all factors
        ll fi = 0;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                int div1 = j;
                int div2 = i / j;

                fi = (div1 * f[div2] + div2 * f[div1]) % mod;

                sumF[i] = (f[div1] + sumF[i]) % mod;

                if (div1 != div2)
                    sumF[i] = (f[div2] + sumF[i]) % mod;
            }
        }

        if (fi == 0)
            f[i] = 1;
        else
            f[i] = fi;

        sumF[i] = (sumF[i] + f[i]) % mod;
        sumF[i] = (sumF[i] + sumF[i - 1]) % mod;
    }

    // REP(i, 1, 7)
    // cout << sumF[i] << endl;

    int t = 1;

    cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}