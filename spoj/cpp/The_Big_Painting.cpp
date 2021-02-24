#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 2011
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int hp, wp, hm, wm;
ll power[maxN];
char paint[maxN][maxN];
ll paintHash[maxN][maxN];
ll masterHash[maxN][maxN];
ll dumHash[maxN][maxN];
ll masterColHash[maxN][maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll paintColHash1 = 0;
    ll paintColHash2 = 0;
    power[0] = 1;
    cin >> hp >> wp >> hm >> wm;

    int cnt = 0;

    REP(i, 1, maxN)
    power[i] = 31 * power[i - 1];

    REP(i, 1, hp + 1)
    {
        REP(j, 1, wp + 1)
        {
            cin >> paint[i][j];
            dumHash[i][j] = (dumHash[i][j - 1] + (paint[i][j] == 'x' ? 1 : 2) * power[j]) % mod;
            paintHash[i][j] = (dumHash[i][j] + paintHash[i - 1][j]) % mod;
        }
    }

    // finding hash of first row of a paint matrix
    REP(i, 1, hp + 1)
    {
        paintColHash1 = (paintColHash1 + (paint[i][1] == 'x' ? 1 : 2) * power[i]) % mod;
        paintColHash2 = (paintColHash2 + (paint[i][wp] == 'x' ? 1 : 2) * power[i]) % mod;
    }

    REP(i, 1, hm + 1)
    {
        REP(j, 1, wm + 1)
        {
            cin >> paint[i][j];
            dumHash[i][j] = (dumHash[i][j - 1] + (paint[i][j] == 'x' ? 1 : 2) * power[j]) % mod;
            masterHash[i][j] = (dumHash[i][j] + masterHash[i - 1][j]) % mod;
        }
    }

    // hashing rows of masterpiece
    REP(j, 1, wm + 1)
    {
        REP(i, 1, hm + 1)
        {
            masterColHash[i][j] = (masterColHash[i - 1][j] + (paint[i][j] == 'x' ? 1 : 2) * power[i]) % mod;
        }
    }

    for (int lr = 1, rr = hp; rr <= hm; rr++, lr++)
    {
        for (int lc = 1, rc = wp; rc <= wm; rc++, lc++)
        {
            // finding hash of the part
            ll mhash = (masterHash[rr][rc] - masterHash[lr - 1][rc] - masterHash[rr][lc - 1] + masterHash[lr - 1][lc - 1] + 4LL * mod) % mod;

            // finding hash of first column of paint
            bool flag1 = (masterColHash[rr][lc] - masterColHash[lr - 1][lc] + mod * 4LL) % mod == (paintColHash1 * power[lr - 1] % mod);
            bool flag2 = (masterColHash[rr][rc] - masterColHash[lr - 1][rc] + mod * 4LL) % mod == (paintColHash2 * power[lr - 1] % mod);

            if (mhash == (paintHash[hp][wp] * power[lc - 1]) % mod && flag1 && flag2)
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}