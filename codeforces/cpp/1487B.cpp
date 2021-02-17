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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

void posChange(ll n, ll k)
{
    ll period = (n / 2) * n;
    ll a, b;

    k = k % period;

    while (k > 0)
    {
        int mid = n / 2;
        
        if(k < mid)
        {
            cout << k << endl;
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    ll n, k, a, b;

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        if (n % 2 == 0)
        {
            k = k % n;
            b = k == 0 ? 1 : k;
        }
        else
        {
        }

        cout << b << endl;
    }

    return 0;
}