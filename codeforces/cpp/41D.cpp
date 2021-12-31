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
 
int N,M,K;
int arr[101][101];
int dp[101][101][1000];
 
bool isValid(int x, int y)
{
    if(x<1||y<1||x>N||y>M)
        return false;
    return true;
}
 
// from i = n to reach i = 1
ll fun(int i, int j, int sum=0)
{
    if(i==1)
    {
        sum+=arr[i][j];
        return (sum%K?-INF:sum);
    }
    else if(dp[i][j][sum] != -1)
        return dp[i][j][sum];
    else
    {
        ll l=-INF;
        ll r=-INF;
 
        if(isValid(i-1,j-1))
            l=fun(i-1,j-1,sum+arr[i][j]);
        if(isValid(i-1,j+1))
            r=fun(i-1,j+1,sum+arr[i][j]);
        return dp[i][j][sum] = max(l,r);
    }
}
 
 
void solve()
{
    memset(dp,-1,sizeof(dp));
 
	cin>>N>>M>>K;
    K++;
 
    REP(i,1,N)
    {
        REP(j,1,M)
        {
            char c;
            cin>>c;
            arr[i][j]=c-'0';
        }
    }
 
    ll ans=-INF;
    int index = 0;
 
    REP(i,1,M)
    {
        if(fun(N,i)>ans)
        {
            ans=fun(N,i);
            index=i;
        }
    }
 
    if(ans==-INF)
    {
        cout<<-1<<endl;
        return;
    }
    
    cout<<ans<<endl;
    cout<<index<<endl;
 
    // finding path
    string path;
 
    int i = N, j = index;
    int sum = 0;
 
    while (i>1)
    {
        sum+=arr[i][j];
 
        if(fun(i-1,j-1,sum)>=fun(i-1,j+1,sum) && j>1)
        {   
            path.push_back('L');
            j--;
        }
        else
        {
            path.push_back('R');
            j++;
        }
        
        i--;
    }
    
    cout<<path;
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
