#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 200001
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

    cin>>n;
    cin>>s;

    int arr[n+1] = {0};
    int end = n;

    RREP(i,s.size()-1,0)
    {
        if(s[i]=='<')
            arr[i+2]=end--;
    }

    REP(i,1,n)
    {
        if(arr[i])
            cout<<arr[i]<<" ";
        else
            cout<<end<<" ", end--;
        
        arr[i] = 0;
    }
    cout<<endl;

    int start = 1;

    REP(i,1,n)
    {
        if(arr[i])
            cout<<arr[i]<<" ";
        else
            cout<<start<<" ", start++;
    }
    cout<<endl;

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