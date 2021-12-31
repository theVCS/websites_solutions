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

string str1, str2;
// ll dp[10][2][2][82];
int N;
string num;
// flag1 -> for lower bound
// flag2 -> for upper bound

ll digitDP(int pos, int flag1 = 1, int flag2 = 1, ll res = 1, int nonZero=0)
{
    if (pos < 0)
        return res;
    // else if (dp[pos][flag1][flag2][res] != -1)
    //     return dp[pos][flag1][flag2][res];
    else
    {
        ll ans = -1;
        int lb = flag1 ? (str1[pos] - '0') : 0;
        int ub = flag2 ? (str2[pos] - '0') : 9;

        REP(i, lb, ub)
        {
            ll v = digitDP(pos - 1, (i == lb & flag1), (i == ub & flag2), res*((nonZero||i)?i:1), nonZero||i);

            if(ans<v)
            {
                ans=v;
                if(num.size()==pos+1)
                num.pop_back();
                num.push_back(char('0'+i));
            }
        }

        // return dp[pos][flag1][flag2][res] = ans;
        return ans;
    }
}

void solve()
{
    cin >> str1 >> str2;

    if (str1[0] == '-')
    {
        return;
    }

    // str1 -> lower bound
    // str2 -> upper bound

    N = str2.size();

    reverse(all(str1));
    reverse(all(str2));

    while (str1.size() < str2.size())
    {
        str1.push_back('0');
    }

    // memset(dp, -1, sizeof(dp));
    cout << digitDP(N - 1) << endl;
    cout << num << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}