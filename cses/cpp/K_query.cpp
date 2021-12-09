#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 30001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

const int arrSize = 30001;
int arr[arrSize];

template <class T>
class mergeSortTree
{
    int n;
    vector<T> segTree[4 * arrSize];

public:
    mergeSortTree() {}

    mergeSortTree(int N)
    {
        n = N;
    }

    void resize(int N)
    {
        n = N;
    }

    void _build_(int si, int ss, int se)
    {
        if (ss == se)
        {
            segTree[si].push_back(arr[ss]);
        }
        else
        {
            int mid = (ss + se) / 2;

            _build_(2 * si, ss, mid);
            _build_(2 * si + 1, mid + 1, se);

            int i = 0, j = 0;

            while (i < segTree[2 * si].size() && j < segTree[2 * si + 1].size())
                if (segTree[2 * si][i] < segTree[2 * si + 1][j])
                    segTree[si].push_back(segTree[2 * si][i++]);
                else
                    segTree[si].push_back(segTree[2 * si + 1][j++]);

            while (i < segTree[2 * si].size())
                segTree[si].push_back(segTree[2 * si][i++]);

            while (j < segTree[2 * si + 1].size())
                segTree[si].push_back(segTree[2 * si + 1][j++]);
        }
    }

    void build()
    {
        _build_(1, 1, n);
    }

    int bs(int si, T val)
    {
        int start = 0, end = segTree[si].size() - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (segTree[si][mid] <= val && (mid == end || segTree[si][mid + 1] > val))
                return segTree[si].size() - 1 - mid;
            else if (segTree[si][mid] <= val)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return segTree[si].size();
    }

    T _query_(int si, int ss, int se, int qs, int qe, T val)
    {
        if (qs > se || qe < ss)
            return 0;

        if (qs <= ss && qe >= se)
            return bs(si, val);

        int mid = (ss + se) / 2;

        return _query_(2 * si, ss, mid, qs, qe, val) + _query_(2 * si + 1, mid + 1, se, qs, qe, val);
    }

    T query(int l, int r, T val)
    {
        return _query_(1, 1, n, l, r, val);
    }
};

void solve()
{
    int n, q;

    cin >> n;

    mergeSortTree<ll> segTree(n);

    REP(i, 1, n)
    cin >> arr[i];

    segTree.build();

    cin >> q;

    REP(i, 1, q)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << segTree.query(l, r, k) << endl;
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

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}