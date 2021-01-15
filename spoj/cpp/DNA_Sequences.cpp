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
int t[1010][1010];

int lcs(string a, string b)
{
    int n = a.size(), m = b.size();
    string s;

    REP(i, 1, n + 1)
    REP(j, 1, m + 1)
    {
        if (a[i - 1] == b[j - 1])
        {
            t[i][j] = 1 + t[i - 1][j - 1];
            s = s + a[i - 1];
        }
        else
        {
            t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    // REP(i, 0, n + 1)
    // {
    //     REP(j, 0, m + 1)
    //     {
    //         cout << t[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << s << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    string a, b;

    while (true)
    {
        cin >> k;

        if (k == 0)
        {
            return 0;
        }

        cin >> a >> b;
        lcs(a, b);
    }

    return 0;
}