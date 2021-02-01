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

    int t, n;
    ll dum, k;

    cin >> t;

    while (t--)
    {
        map<ll, int> mp;

        cin >> n >> k;

        REP(i, 0, n)
        {
            cin >> dum;
            mp[(dum % k)]++;
        }

        bool flag = true;

        for (auto e : mp)
        {
            if (mp[k - e.first] || e.first == 0)
            {
                mp[k - e.first] = 0;
            }
            else
            {
                if (e.first % 2 == 0 && 2 * e.first == k)
                {
                    mp[e.first] = 0;
                }
                else
                {
                    cout << "NO" << endl;
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}