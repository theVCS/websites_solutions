#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int n, m, dum, p;
ll arr[maxN], l, d;

void timCa()
{
    int ans = 0;

    for (ll i = 1; i <= n; i+=l)
    {
        
    }
    
}

void upd(int p, ll d)
{
    arr[p] += d;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> l;

    REP(i, 1, n + 1)
    {
        cin >> arr[i];
    }

    while (m--)
    {
        cin >> dum;

        if (dum)
        {
            cin >> p >> d;
            upd(p, d);
        }
        else
        {
            timCa();
        }
    }

    return 0;
}