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

int n, k, family[1001];

ll ineff()
{
    ll dp[n + 1];
    int newTable = 1;
    map<int, int> familMap;

    dp[1] = k;
    familMap[family[1]]++;

    for (int i = 2; i < n + 1; i++)
    {
        if (familMap[family[i]])
        {
            familMap[family[i]]++;

            if (familMap[family[i]] == 2)
            {
                dp[i] = min(dp[i - 1] + 2, dp[i - 1] + k);
            }
            else
            {
                dp[i] = min(dp[i - 1] + 1, dp[i - 1] + k);
            }

            if (dp[i] == dp[i - 1] + k)
            {
                cout << newTable << " to " << i << endl;
                newTable = i;
                familMap.clear();
                familMap[family[i]]++;
            }
        }
        else
        {
            dp[i] = dp[i - 1];
            familMap[family[i]]++;
        }
    }

    return dp[n];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        cin >> n >> k;

        REP(i, 1, n + 1)
        cin >> family[i];

        cout << ineff() << endl;
    }

    return 0;
}