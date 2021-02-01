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

int res[100010][2];
int ones[100010], zeros[100010];

int lcs(string s, int n, int i = -1, char lastChar = '0')
{
    if (i >= n - 1)
    {
        return 0;
    }
    else if (res[i + 1][int(lastChar - '0')] != -1)
    {
        return res[i + 1][int(lastChar - '0')];
    }
    else if (lastChar == '0')
    {
        ++i;

        int zind = zeros[i], oind = ones[i];

        if (zind >= n && oind >= n)
        {
            return res[i][int(lastChar - '0')] = 0;
        }

        return res[i][int(lastChar - '0')] = 1 + max(lcs(s, n, zind, '0'), lcs(s, n, oind, '1'));
    }
    else
    {
        ++i;
        int oind = ones[i];

        if (oind >= n)
        {
            return res[i][int(lastChar - '0')] = 0;
        }

        return res[i][int(lastChar - '0')] = 1 + lcs(s, n, oind, '1');
    }
}

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

        int oind = n + 10, zind = n + 10;

        res[n][0] = res[n][1] = -1;
        res[n + 1][0] = res[n + 1][1] = -1;

        for (int i = n - 1; i >= 0; i--)
        {
            res[i][0] = res[i][1] = -1;

            if (s[i] == '1')
            {
                oind = i;
            }

            if (s[i] == '0')
            {
                zind = i;
            }

            ones[i] = oind;
            zeros[i] = zind;
        }

        cout << n - lcs(s, n) << endl;
    }

    return 0;
}