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
    string s;

    cin >> t;

    while (t--)
    {
        cin >> n;
        cin >> s;

        string res = s;

        res[0] = '2' - s[0] + '0' - 1;

        for (int i = 1; i < n; i++)
        {
            if (s[i] = '0')
            {
                if (res[i - 1] == '0')
                {
                    res[i] = '1';
                }
                else
                {
                    res[i] = '0';
                }
            }
            else
            {
                if (res[i - 1] == '0')
                {
                    res[i] = '1';
                }
                else
                {
                    res[i] = '0';
                }
            }
        }

        cout <<  res << endl;
    }

    return 0;
}