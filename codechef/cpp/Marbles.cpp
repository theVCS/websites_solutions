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

int isVowel(char c)
{
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

void solve()
{
    int n;
	string s,t;
    cin>>n>>s>>t;

    int ans=INF;

    for (char c = 'a'; c <= 'z'; c++)
    {
        int res = 0;

        REP(i,0,n-1)
        {
            int sc = s[i]=='?'?c:s[i];
            int tc = t[i]=='?'?c:t[i];

            if(sc==tc)continue;

            if(isVowel(sc)^isVowel(tc))res++;
            else res+=2;
        }

        ans=min(ans,res);
    }
    
    cout<<ans<<endl;
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