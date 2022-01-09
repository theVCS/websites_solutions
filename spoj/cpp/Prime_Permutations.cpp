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

const int totNum=1e7;
bool primer[totNum/2+10];

void init()
{
    primer[0] = primer[1] = true;

    for (int i = 3; i * i <= totNum; i+=2)
    {
        if (primer[(i+1)/2] == false)
        {
            for (int j = i * i; j <= totNum; j+=2*i)
            {
                primer[(j+1)/2] = true;
            }
        }
    }
}

bool isPrime(int n)
{
    if(n==2)return true;
    if(n<2||n%2==0)return false;
    return primer[(n+1)/2]==false;
}

void solve()
{
    string s;
    cin>>s;
    string p=s;
    int cnt=0;

    while (true)
    {
        if(p[0]!='0' && isPrime(stoi(p)))cnt++;
        next_permutation(all(p));
        if(p==s)break;
    }
    
    cout<<cnt<<endl;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
    init();

	int t = 1;

	cin >> t;

	REP(tc, 1, t)
	{
		// cout<<"Case "<<tc<<":"<<endl;
		solve();
	}

	return 0;
}