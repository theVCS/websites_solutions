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

int cnt[64][2];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    ll dum, res;
    cin >> t;

    while (t--)
    {
        res = 0;

        cin >> n;

        while (n--)
        {
            cin >> dum;

            REP(i, 0, 63)
            {
                if (1LL << i & dum)
                    cnt[i][1]++;
                else
                    cnt[i][0]++;
            }
        }

        REP(i, 0, 63)
        {
            dum = 1LL << i;

            if (cnt[i][0] < cnt[i][1])
                res += dum;

            cnt[i][0] = cnt[i][1] = 0;
        }

        cout << res << endl;
    }

    return 0;
}