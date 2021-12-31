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

string num;
int N;
ll dp[12][1<<12];

ll fun(int index, int carry = 0)
{
    if (carry >= (1 << (N)))
        return 0;
    if (index == -1)
    {
        return 1;
    }
    else if(dp[index][carry] != -1)
        return dp[index][carry];
    else
    {
        ll ans = 0;
        int lastDigit = num[index] - '0';

        REP(i, 0, 9)
        {
            REP(j, 0, 9)
            {
                int bitIndex = (N - 1 - index);
                int sum = (i + j + ((carry >> bitIndex) & 1));

                if (sum % 10 == lastDigit)
                {
                    if (sum > 9)
                        ans += fun(index - 1, carry | (1 << (bitIndex + 2)));
                    else
                        ans += fun(index - 1, carry);
                }
            }
        }

        return dp[index][carry] = ans;
    }
}

void solve()
{
    cin >> num;
    memset(dp,-1,sizeof(dp));
    N = num.size();
    cout << fun(N - 1) - 2 << endl;
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