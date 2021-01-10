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

ll dp[50001];

void ugly(int n)
{

    int two_index, three_index, five_index;
    two_index = three_index = five_index = 0;

    ll dum;

    dp[0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        dum = min(2 * dp[two_index], min(3 * dp[three_index], 5 * dp[five_index]));

        dp[i] = dum;

        if (dum == 2 * dp[two_index])
        {
            if (dum == dp[i - 1])
            {
                two_index++;
                i--;
            }
            else
            {
                two_index++;
            }
        }
        else if (dum == 3 * dp[three_index])
        {
            if (dum == dp[i - 1])
            {
                three_index++;
                i--;
            }
            else
            {
                three_index++;
            }
        }
        else
        {
            if (dum == dp[i - 1])
            {
                five_index++;
                i--;
            }
            else
            {
                five_index++;
            }
        }
    }

    // return dp[n - 1];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1848;
    ugly(n);

    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }

    return 0;
}