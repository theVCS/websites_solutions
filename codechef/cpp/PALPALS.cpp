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

int cnt[26];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string s;

    cin >> t;

    while (t--)
    {
        cin >> s;

        for (char c : s)
            cnt[c - 'a']++;

        int even = 0, one = 0;

        REP(i, 0, 26)
        {
            if (cnt[i])
            {
                if (cnt[i] == 1)
                    one++;
                else if (cnt[i] % 2 == 1)
                    even++, one++;
                else if (cnt[i] % 2 == 0)
                    even++;

                cnt[i] = 0;
            }
        }

        if (even >= one)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}