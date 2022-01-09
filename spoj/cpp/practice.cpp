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

const int N = 3;
int n = 2;
ll matrix[N][N];
ll identity[N][N];
ll res[N][N];

void multiply(ll a[][N], ll b[][N])
{
    REP(i, 1, n)
    {
        REP(j, 1, n)
        {
            res[i][j] = 0;

            REP(k, 1, n)
            {
                a[i][k] %= mod;
                b[k][j] %= mod;
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }

    REP(i,1,n)
    REP(j,1,n)
    a[i][j]=res[i][j];
}

void matExp(long long p)
{
    while (p)
    {
        if (p & 1)
            multiply(identity, matrix);
        multiply(matrix, matrix);
        p >>= 1;
    }
}

ll fib(long long p)    // n = p where n is nth fib number
{
    p %= 2000000016;
    p--;

    identity[1][1] = identity[2][2] = 1;
    identity[1][2] = identity[2][1] = 0;

    matrix[1][1] = 0;
    matrix[1][2] = matrix[2][1] = matrix[2][2] = 1;

    matExp(p);

    // 0 1 1 2 3 5 so on
    // return identity[1][2];

    //1 1 2 3 5
    return identity[2][2];

    // 1 2 3 5
    // return (identity[2][1] + identity[2][2]) % mod;
}

void solve()
{
	cout<<fib(15);
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