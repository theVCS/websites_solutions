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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    ll n;

    while (t--)
    {
        cin >> n;

        if (n == 2 || (n & 1 && n != 1))
        {
            cout << "Ashishgup\n";
        }
        else if (n == 1)
        {
            cout << "FastestFinger\n";
        }
        else
        {
            ll nnew = 1, dum = n;
            int p = 0;
            bool flag = true;

            while (n % 2 == 0)
            {
                n /= 2;
                p++;
            }
            
            if (n == 1)
            {
                cout << "FastestFinger\n";
            }
            else if (n % 2 && p > 1)
            {
                cout << "Ashishgup\n";
            }
            else
            {
                cout << "FastestFinger\n";
            }
        }
    }

    return 0;
}