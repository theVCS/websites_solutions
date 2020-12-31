#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool hb[100], hg[100];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m, b, g, dum, day = 0;
    bool flag1 = true, flag2 = true;

    cin >> n >> m;

    cin >> b;

    REP(i, 0, b)
    {
        cin >> dum;
        hb[dum] = true;
    }

    cin >> g;

    REP(i, 0, g)
    {
        cin >> dum;
        hg[dum] = true;
    }

    b = day % n;
    g = day % m;

    if (hb[b] || hg[g])
    {
        hb[b] = hg[g] = true;
    }

    day++;

    b = day % n;
    g = day % m;

    while (b != 0 || g != 0)
    {
        if (hb[b] || hg[g])
        {
            hb[b] = hg[g] = true;
        }
        day++;
        b = day % n;
        g = day % m;
    }

    REP(i, 0, n)
    {
        if (hb[i] == false)
        {
            flag1 = false;
            break;
        }
    }

    REP(i, 0, m)
    {
        if (hg[i] == false)
        {
            flag2 = false;
            break;
        }
    }

    if (flag1 || flag2)
    {
        cout << "Yes";
        return 0;
    }

    cout << "No";

    return 0;
}