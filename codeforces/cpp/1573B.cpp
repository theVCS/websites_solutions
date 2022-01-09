#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 100001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

template <class T>
class SegmentTree
{
    int n;
    vector<T> segTree;

public:
    SegmentTree() {}

    SegmentTree(int N)
    {
        n = N;
        segTree.assign(4 * n,INF);
    }

    T _query_(int si, int ss, int se, int qs, int qe)
    {
        if (qs > se || qe < ss)
            return INF;
        if (qs <= ss && qe >= se)
            return segTree[si];
        int mid = (ss + se) / 2;
        return min(_query_(2 * si, ss, mid, qs, qe), _query_(2 * si + 1, mid + 1, se, qs, qe));
    }

    T query(int l, int r)
    {
        return _query_(1, 1, n, l, r);
    }

    void _update_(int si, int ss, int se, int qi, T val)
    {
        if (ss == se)
        {
            segTree[si] = val;
        }
        else
        {
            int mid = (ss + se) / 2;
            if (qi <= mid)
                _update_(2 * si, ss, mid, qi, val);
            else
                _update_(2 * si + 1, mid + 1, se, qi, val);
            segTree[si] = min(segTree[2 * si], segTree[2 * si + 1]);
        }
    }

    void update(int qi, T val)
    {
        _update_(1, 1, n, qi, val);
    }
};

int n;
int index[2*maxN];

void solve()
{
	cin>>n;
    SegmentTree<int>segTree(n);

    REP(i,1,n)
    {
        int x;
        cin>>x;
        index[x]=i;
    }

    REP(i,1,n)
    {
        int x;
        cin>>x;
        segTree.update(x/2,i);
    }

    int mn=INF;

    for (int i = 1; i <= 2*n; i+=2)
    {
        int sm=segTree.query((i+1)/2,n);
        mn=min(mn,sm-1+index[i]-1);
    }
    
    cout<<mn<<endl;
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