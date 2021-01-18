#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll t[200000001];

ll lsb(ll a)
{
    ll cnt = 0;

    while (true)
    {
        if (a & 1)
        {
            cnt++;
            return cnt;
        }
        a >>= 2;
        cnt++;
    }
}

void init()
{
    ll _lsb_;

    t[0] = t[1] = 0;

    for (int i = 2; i < maxN; i++)
    {
        _lsb_ = lsb(i * (i - 1));
        _lsb_ = _lsb_ * _lsb_  * _lsb_;

        t[i] = _lsb_ + t[i - 2];
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int cs;
    ll n;

    cin >> cs;

    while (cs--)
    {
        cin >> n;
        cout << t[n] << endl;
    }

    return 0;
}