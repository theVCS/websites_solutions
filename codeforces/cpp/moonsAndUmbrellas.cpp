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
#define INF 1000000000
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

int x, y;
int res[maxN][2];
int ans;

void dp(string s, int index, int n)
{
    if (index == n)
    {
        ans = 0;

        REP(i,1,s.size())
        {
            if(s[i] != s[i - 1])
            {
                if(s[i - 1] == 'C')
                {
                    ans+=x;
                }
                else
                {
                    ans+=y;
                }
                
            }
        }
    }
    else if (s[index] == '?')
    {
        if (index > 0)
            res[index][1] = res[index][0] = min(res[index - 1][0], res[index - 1][1]);

        if (index > 0 && s[index - 1] == 'J')
            res[index][0] += y;
        dp(s, index + 1, n);

        if (index > 0 && s[index - 1] == 'C')
            res[index][1] += x;

        if (res[index][0] < res[index][1])
        {
            s[index] = 'C';
            res[index][1] = res[index][0];
            dp(s, index + 1, n);
        }
        else
        {
            s[index] = 'J';
            res[index][0] = res[index][1];
            dp(s, index + 1, n);
        }

        return;
    }
    else
    {
        if (index > 0)
        {
            res[index][1] = res[index][0] = min(res[index - 1][0], res[index - 1][1]);

            if (s[index] == 'C' && s[index - 1] == 'J')
                res[index][0] += y;
            if (s[index] == 'J' && s[index - 1] == 'C')
                res[index][0] += x;

            res[index][1] = res[index][0];
        }

        dp(s, index + 1, n);
    }
}

void solve()
{
    string s;

    cin >> x >> y;
    cin >> s;

    ans = INT_MAX;

    memset(res, 0, sizeof(res));
    dp(s, 0, s.size());

    // cout << endl;
    // REP(i, 0, s.size())
    // {
    //     cout << res[i][0] << " " << res[i][1] << endl;
    // }

    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    cin >> t;

    REP(i, 1, t + 1)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}