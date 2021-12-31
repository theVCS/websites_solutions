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

int N;
string str;
ll po[20];
ll dp[19][19][40];

ll fun(int lenA = 0, int lenB = 0, int pos = 0)
{
    if (pos >= 2 * N)
        return 0;
    else if(dp[lenA][lenB][pos]!=-1)
        return dp[lenA][lenB][pos];
    else
    {
        ll ans = 0;

        if (lenA < N)
            ans = fun(lenA + 1, lenB, pos + 1) + (str[pos] - '0') * po[N - lenA - 1];

        if (lenB < N)
            ans = max(ans, fun(lenA, lenB + 1, pos + 1) + (str[pos] - '0') * po[N - lenB - 1]);

        return dp[lenA][lenB][pos] = ans;
    }
}

void solve()
{
    cin >> N >> str;
    
    po[0] = 1;
    REP(i, 1, 18)
    po[i] = po[i - 1] * 10;

    memset(dp,-1,sizeof(dp));
    fun();

    string res;
    int  lenA = 0, lenB = 0;

    while (lenA+lenB<2*N)
    {
        int pos=lenA+lenB;

        if(lenA<N && fun(lenA,lenB,pos)==fun(lenA + 1, lenB, pos + 1) + (str[pos] - '0') * po[N - lenA - 1])lenA++, res.push_back('H');
        else lenB++, res.push_back('M');
    }
    
    cout<<res;
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