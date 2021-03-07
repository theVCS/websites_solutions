#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 201
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int res[maxN];
bool ans;

void graphBuilder(string s, int n, int col[], int index[], string sorStr)
{
    bool flag = true;

    REP(i, 1, n)
    {
        if (s[i] < s[i - 1])
        {
            if (col[index[i]] > -1 && col[index[i - 1]] > -1)
            {
                if (col[index[i]] != col[index[i - 1]])
                {
                    string t = s;
                    swap(t[i], t[i - 1]);
                    swap(index[i], index[i - 1]);
                    graphBuilder(t, n, col, index, sorStr);
                    flag = false;
                }
                else
                {
                    return;
                }
            }
            else
            {
                if (col[index[i]] == -1 && col[index[i - 1]] == -1)
                {
                    col[index[i]] = 1;
                    col[index[i - 1]] = 0;
                }
                else if (col[index[i]] == -1)
                {
                    col[index[i]] = 1 ^ col[index[i - 1]];
                }
                else
                {
                    col[index[i - 1]] = 1 ^ col[index[i]];
                }

                string t = s;
                swap(t[i], t[i - 1]);
                swap(index[i], index[i - 1]);
                graphBuilder(t, n, col, index, sorStr);
                flag = false;
            }
        }
    }

    if (flag && s == sorStr)
    {
        REP(i, 0, n)
        res[i] = (col[i] > 0);

        ans = true;

        return;
    }
}

void solve()
{
    int n;
    string s;
    char ch;

    cin >> n;

    int col[n];
    int index[n];

    cin >> s;

    REP(i, 0, n)
    {
        col[i] = -1;
        index[i] = i;
    }

    string t = s;
    sort(all(t));

    graphBuilder(s, n, col, index, t);

    if (ans)
    {
        cout << "YES\n";

        REP(i, 0, n)
        cout << res[i];
    }
    else
    {
        cout << "NO";
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}