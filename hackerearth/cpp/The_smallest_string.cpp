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

    int t, n, k;
    string s;

    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        cin >> s;

        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                int v = s[i] - 'a';
                v = (v + k) % 26;
                s[i] = char(v + 'a');
                break;
            }

            int v = s[i] - 'a';
            int reqV = 26 - v;

            if (reqV <= k && v)
            {
                k -= reqV;
                s[i] = 'a';
            }

            if (k == 0)
                break;
        }

        cout << s << endl;
    }

    return 0;
}