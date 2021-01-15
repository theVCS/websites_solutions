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

string lcs(string a, string b)
{
    int n = a.size(), m = b.size();
    int t[n + 1][m + 1];

    REP(i, 0, n + 1)
    t[i][0] = 0;
    REP(i, 0, m + 1)
    t[0][i] = 0;

    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            if (a[i - 1] == b[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    int i = n, j = m;
    string s;

    while (i && j)
    {
        if (a[i - 1] == b[j - 1])
        {
            s.push_back(a[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (t[i - 1][j] > t[i][j - 1])
            {
                s.push_back(a[i - 1]);
                i--;
            }
            else
            {
                s.push_back(b[j - 1]);
                j--;
            }
        }
    }

    while (i)
    {
        s.push_back(a[i - 1]);
        i--;
    }
    while (j)
    {
        s.push_back(b[j - 1]);
        j--;
    }

    reverse(s.begin(), s.end());
    return s;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;

    while (cin >> a)
    {
        cin >> b;
        cout << lcs(a, b) << endl;
    }

    return 0;
}