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

void solve()
{
    ll n, num, sb = 0, sbn;
    int res = 1;

    cin >> n;
    cin >> num;

    REP(i, 0, 18)
    {
        if ((1LL << i) & num)
            sb++;
    }

    n--;
    REP(j, 0, n)
    {
        cin >> num;
        sbn = 0;

        REP(i, 0, 18)
        {
            if ((1LL << i) & num)
                sbn++;
        }

        if (abs(sbn - sb) <= 1)
            res++;
    }

    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}