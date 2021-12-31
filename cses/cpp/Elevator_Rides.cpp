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
ll W[21];
ll X;
int dp[1 << 20];
int dp1[20][1<<20];

class myClass
{
public:
    int knapsack(int pos, int mask, int MASK, ll sum=0)
    {
        if(sum>X)
            return INF;
        else if(pos==N)
            return mask!=MASK?1+fun(mask):INF;
        else if(dp1[pos][mask]!=-1)
            return dp1[pos][mask];
        else if(mask & (1<<pos))
            return knapsack(pos+1,mask,MASK,sum);
        else
        {
            int ans = INF;
            ans=min(ans,knapsack(pos+1,mask|(1<<pos),MASK,sum+W[pos]));
            ans=min(ans,knapsack(pos+1,mask,MASK,sum));
            return dp1[pos][mask] = ans;
        }
    }

    int fun(int mask = 0)
    {
        if (mask == (1 << N) - 1)
            return 0;
        else if (dp[mask] != -1)
            return dp[mask];
        else
        {
            return dp[mask] = knapsack(0, mask, mask);
        }
    }
};

void solve()
{
    cin >> N >> X;

    REP(i, 0, N - 1)
    cin >> W[i];

    memset(dp, -1, sizeof(dp));
    memset(dp1, -1, sizeof(dp1));
    myClass obj;
    cout << obj.fun();
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