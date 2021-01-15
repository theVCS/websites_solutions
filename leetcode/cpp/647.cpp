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

class Solution
{
public:
    int countSubstrings(string s)
    {
        string t = s;
        reverse(s.begin(), s.end());

        int n = s.size(), m = s.size(), res = 0;
        int dp[n + 1][m + 1];

        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = dp[0][i] = 0;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                    if (dp[i][j] == 1)
                    {
                        res++;
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    Solution obj;
    cout << obj.countSubstrings(str);

    return 0;
}