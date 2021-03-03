#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 2001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int hp, wp, hm, wm;
ll power[maxN * maxN];
char paint[maxN];
ll paintHash[maxN][maxN];
ll masterHash[maxN][maxN];
ll dumMastHash[maxN][maxN];

ll paintHashCal(int rr, int lr, int rc, int lc)
{
    ll res = 0;

    REP(i, 1, hp + 1)
    {
        int totalEle = (lr + i - 2) * wm + lc - 1 - wp * (i - 1);
        res = (res + paintHash[i][wp] * power[totalEle]) % mod;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d", &hp, &wp, &hm, &wm);
    ll p = 2;
    power[0] = 1;

    REP(i, 1, hp + 1)
    {
        scanf("%s", paint);

        REP(j, 1, wp + 1)
        {
            paintHash[i][j] = (paintHash[i][j - 1] + (paint[j - 1] == 'x' ? 1 : 0) * p) % mod;
            p = (p * 2) % mod;
        }
    }

    int cnt = 1;
    p = 2;

    REP(i, 1, hm + 1)
    {
        scanf("%s", paint);

        REP(j, 1, wm + 1)
        {
            dumMastHash[i][j] = (dumMastHash[i][j - 1] + (paint[j - 1] == 'x' ? 1 : 0) * p) % mod;
            masterHash[i][j] = (dumMastHash[i][j] + masterHash[i - 1][j]) % mod;
            power[cnt] = p;
            p = (p * 2) % mod;
            cnt++;
        }
    }

    cnt = 0;

    for (int lr = 1, rr = hp; rr <= hm; rr++, lr++)
    {
        for (int lc = 1, rc = wp; rc <= wm; rc++, lc++)
        {
            ll mhash = (masterHash[rr][rc] - masterHash[lr - 1][rc] - masterHash[rr][lc - 1] + masterHash[lr - 1][lc - 1] + 2 * mod) % mod;

            if (mhash == paintHashCal(rr, lr, rc, lc))
                cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}