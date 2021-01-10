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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    ll n, x, p, k, dum;

    cin >> t;

    while (t--)
    {
        cin >> n >> x >> p >> k;

        vector<int> arr;
        REP(i, 0, n)
        {
            cin >> dum;
            arr.push_back(dum);
        }

        sort(arr.begin(), arr.end());

        if ((x > arr[p - 1] && k > p) || (x < arr[p - 1] && k < p))
        {
            cout << -1 << endl;
        }
        else if (arr[p - 1] == x)
        {
            cout << 0 << endl;
        }
        else
        {
            int i = 0;

            while (arr[i] <= x)
            {
                i++;
            }

            if (i)
            {
                if (arr[i - 1] == x)
                {
                    i--;
                }
            }
            cout << abs(p - x) << endl;
        }
    }

    return 0;
}