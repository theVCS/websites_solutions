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

bool check(string s)
{
    if (s.size() < 10)
        return false;

    int lc = 0, uc = 0, digc = 0, cc = 0, ucsi = 0, digsi = 0, ccsi = 0;

    char ch[] = {'@', '#', '%', '&', '?'};

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            lc++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            uc++;

            if (i > 0 && i < s.size() - 1)
            {
                ucsi++;
            }
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            digc++;

            if (i > 0 && i < s.size() - 1)
            {
                digsi++;
            }
        }
        else
        {
            cc++;

            if (i > 0 && i < s.size() - 1)
            {
                ccsi++;
            }
        }
    }

    if (lc && uc && digc && cc && ucsi && digsi && ccsi)
    {
        return true;
    }
    return false;
}

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

        if (check(s))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}