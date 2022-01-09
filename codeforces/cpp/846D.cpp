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
#define INF 2000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

template <class T>
class FenwickTree2D
{
    int n, m;
    vector<vector<T>> BIT;

public:
    FenwickTree2D() {}

    FenwickTree2D(int N, int M)
    {
        n = N;
        m = M;
        BIT.resize(n + 1);

        for (vector<T> &vec : BIT)
            vec.assign(m + 1, 0);
    }

    void resize(int N, int M)
    {
        n = N;
        m = M;
        BIT.resize(n + 1);

        for (vector<T> &vec : BIT)
            vec.assign(m + 1, 0);
    }

    T _query_(int x, int y)
    {
        T sum = 0;

        for (int i = x; i > 0; i -= (i & -i))
        {
            for (int j = y; j > 0; j -= (j & -j))
            {
                sum += BIT[i][j];
            }
        }

        return sum;
    }

    T query(int x2, int y2, int x1, int y1)
    {
        return _query_(x2, y2) - _query_(x1 - 1, y2) - _query_(x2, y1 - 1) + _query_(x1 - 1, y1 - 1);
    }

    void update(int x, int y, T val)
    {
        for (int i = x; i <= n; i += (i & -i))
        {
            for (int j = y; j <= m; j += (j & -j))
            {
                BIT[i][j] += val;
            }
        }
    }
};

int n, m, k, q;

struct pixel
{
    int x,y,t;
}arr[250001];

bool cmp(pixel &a, pixel &b)
{
    return a.t<b.t;
}

bool isValid(int t)
{
    // cout<<t<<endl;
    FenwickTree2D<int>ft(n,m);

    REP(i,1,t)
        ft.update(arr[i].x,arr[i].y,1);
    
    REP(i,k,n)
    {
        REP(j,k,m)
        {
            if(ft.query(i,j,i-k+1,j-k+1)==k*k)
                return true;
        }
    }

    return false;
}

void solve()
{
	cin>>n>>m>>k>>q;

    REP(i,1,q)
    cin>>arr[i].x>>arr[i].y>>arr[i].t;

    sort(arr+1,arr+1+q,cmp);

    int mn=INF;
    int start=1,end=q;

    while (start<=end)
    {
        int mid=(start+end)/2;
        
        if(isValid(mid))
            mn=min(mn,arr[mid].t),end=mid-1;
        else start=mid+1;
    }

    cout<<(mn==INF?-1:mn)<<endl;
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