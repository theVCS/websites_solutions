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

struct point
{
    int x, y;
}arr[2000];

bool cmp1(point &a, point &b)
{
    return a.x<b.x;
}

bool cmp2(point &a, point &b)
{
    return a.y<b.y;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    int index=0;

    REP(i,1,n)
    REP(j,1,m)
    {
        char c;
        cin>>c;
        if(c=='R')
        {
            index++;
            arr[index].x=i;
            arr[index].y=j;
        }
    }

    sort(arr+1,arr+1+n,cmp1);

    REP(i,2,index)
    {
        if(arr[index].x-arr[index-1].x <= 1)
        {
            cout<<
        }
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