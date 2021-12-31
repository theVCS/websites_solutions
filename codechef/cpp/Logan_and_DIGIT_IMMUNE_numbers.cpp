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
ll dp[19][2][2][2][2][2][3][7][9][2];
ll N, K;

int POS, FLAG1, FLAG2, UT, US, UN, REM3, REM7, REM9, CURRZERO;

// flag1 -> for lower bound
// flag2 -> for upper bound

// can never use 1

ll digitDP(int pos, int flag1 = 1, int flag2 = 1, int ut = 0, int us = 0, int un = 0, int rem3 = 0, int rem7 = 0, int rem9 = 0, int currZero = 1)
{
    if (pos < 0)
    {
        if (ut && rem3 == 0)
            return 0;
        if (us && rem7 == 0)
            return 0;
        if (un && rem9 == 0)
            return 0;
        return 1;
    }
    else if (dp[pos][flag1][flag2][ut][us][un][rem3][rem7][rem9][currZero] != -1)
        return dp[pos][flag1][flag2][ut][us][un][rem3][rem7][rem9][currZero];
    else
    {
        ll ans = 0;
        int lb = flag1 ? (str1[pos] - '0') : 0;
        int ub = flag2 ? (str2[pos] - '0') : 9;

        int LB = lb;
        int UB = ub;

        lb = max(lb, 3);
        ub = min(9, ub);

        if (lb % 2 == 0)
            lb++;

        // cout<<lb<<" "<<ub<<" "<<currZero<<endl;

        if (lb > ub && currZero)
            return digitDP(pos - 1, flag1 & LB == 0, flag2 & UB == 0, ut, us, un, rem3, rem7, rem9, 1);

        if (lb > ub)
            return 0;

        for (int i = lb; i <= ub; i += 2)
        {
            if (pos == 0 && i == 5)
                continue;
            ans += digitDP(pos - 1, (i == LB & flag1), (i == UB & flag2), ut || (i == 3), us || (i == 7), un || (i == 9), (rem3 * 10 + i) % 3, (rem7 * 10 + i) % 7, (rem9 * 10 + i) % 9, 0);
        }

        if (ans >= K && POS == 0 && currZero)
        {
            POS = pos, FLAG1 = flag1, FLAG2 = flag2, UT = ut, US = us, UN = un, REM3 = rem3, REM7 = rem7, REM9 = rem9, CURRZERO = currZero;
        }

        return dp[pos][flag1][flag2][ut][us][un][rem3][rem7][rem9][currZero] = ans;
        // return ans;
    }
}

void solve()
{
    // str1 -> lower bound
    // str2 -> upper bound
    cin >> str1 >> str2 >> K;

    N = str2.size();

    reverse(all(str1));
    reverse(all(str2));

    while (str1.size() < str2.size())
    {
        str1.push_back('0');
    }

    POS = 0;
    memset(dp, -1, sizeof(dp));
    ll ans = digitDP(N - 1);

    if (ans < K)
    {
        cout << -1 << endl;
        return;
    }

    string res = "";

    while (POS >= 0)
    {
        int pos = POS, flag1 = FLAG1, flag2 = FLAG2, ut = UT, us = US, un = UN, rem3 = REM3, rem7 = REM7, rem9 = REM9, currZero = CURRZERO;

        int lb = flag1 ? (str1[pos] - '0') : 0;
        int ub = flag2 ? (str2[pos] - '0') : 9;

        int LB = lb;
        int UB = ub;

        lb = max(lb, 3);
        ub = min(9, ub);

        if (lb % 2 == 0)
            lb++;

        for (int i = lb; i <= ub; i += 2)
        {
            if (pos == 0 && i == 5)
                continue;

            ll ans = digitDP(pos - 1, (i == LB & flag1), (i == UB & flag2), ut || (i == 3), us || (i == 7), un || (i == 9), (rem3 * 10 + i) % 3, (rem7 * 10 + i) % 7, (rem9 * 10 + i) % 9, currZero);

            if (ans >= K)
            {
                res.push_back(char(i + '0'));

                POS = pos - 1, FLAG1 = (i == LB & flag1), FLAG2 = (i == UB & flag2), UT = ut || (i == 3), US = us || (i == 7), UN = un || (i == 9), REM3 = (rem3 * 10 + i) % 3, REM7 = (rem7 * 10 + i) % 7, REM9 = (rem9 * 10 + i) % 9, CURRZERO = 0;

                break;
            }
            else
            {
                K -= ans;
            }
        }
    }

    cout << res << endl;
    // 37
    // 53
    // 57
    // 59
    // 73
    // 79
    // 97
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