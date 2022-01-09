#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> two, one;

    REP(i, 1, n)
    {
        if (s[i - 1] == '1')
            one.push_back(i);
        else
            two.push_back(i);
    }

    if (two.size() > 0 && two.size() <= 2)
    {
        cout << "NO" << endl;
        return;
    }

    char res[51][51];

    REP(i, 1, n)
    {
        bool flag = true;

        REP(j, i, n)
        {
            // if (i > j)
            //     break;

            if (i == j)
            {
                res[i][j] = 'X';
                continue;
            }

            if (s[i - 1] == '1' || s[j - 1] == '1')
            {
                res[i][j] = '=';
                res[j][i] = '=';
                continue;
            }

            if (flag)
            {
                res[i][j] = '+';
                res[j][i] = '-';
                flag = false;
            }
            else
            {
                res[i][j] = '-';
                res[j][i] = '+';
            }
        }
    }

    cout << "YES" << endl;

    REP(i, 1, n)
    {
        REP(j, 1, n)
        cout << res[i][j];
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}