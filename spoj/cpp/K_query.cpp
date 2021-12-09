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

int n, q;
int arr[maxN];
int rev[maxN];
map<int, int> mp;
int timer = 0;

int bs(int k)
{
    // index where arr[index] <= k
    int start = 1, end = timer;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (rev[mid] <= k && (mid == end || rev[mid + 1] > k))
            return mid;
        else if (rev[mid] <= k)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return 0; // then answer = size of range
}

template <class T>
class PersistentSegmentTree
{
    int n;
    vector<T> segTree;
    vector<int> left, right;
    vector<int> roots;
    int index;

public:
    PersistentSegmentTree() {}

    int build(int ss, int se)
    {
        int node = ++index;

        if (ss == se)
        {
            segTree[node] = 0;
            return node;
        }
        else
        {
            int mid = (ss + se) / 2;
            left[node] = build(ss, mid);
            right[node] = build(mid + 1, se);
            segTree[node] = 0;
            return node;
        }
    }

    PersistentSegmentTree(int N)
    {
        n = N;
        segTree.resize(N * 21);
        left.resize(N * 21);
        right.resize(N * 21);
        index = 0;
        roots.push_back(build(1, n));
    }

    void resize(int N)
    {
        n = N;
        segTree.resize(N * 21);
        left.resize(N * 21);
        right.resize(N * 21);
        index = 0;
        roots.push_back(build(1, n));
    }

    int _update_(int prevNode, int ss, int se, int qi, T val)
    {
        int node = ++index;

        if (ss == se)
        {
            segTree[node] = segTree[prevNode] + val;
            return node;
        }

        int mid = (ss + se) / 2;

        if (qi <= mid)
        {
            right[node] = right[prevNode];
            left[node] = _update_(left[prevNode], ss, mid, qi, val);
        }
        else
        {
            left[node] = left[prevNode];
            right[node] = _update_(right[prevNode], mid + 1, se, qi, val);
        }

        segTree[node] = segTree[left[node]] + segTree[right[node]];
        return node;
    }

    void update(int index, T val)
    {
        roots.push_back(_update_(roots.back(), 1, n, index, val));
    }

    T _query_(int nodeA, int nodeB, int ss, int se, int qs, int qe)
    {
        if (qs > se || qe < ss)
            return 0;
        if (qs <= ss && qe >= se)
            return segTree[nodeA] - segTree[nodeB];
        int mid = (ss + se) / 2;
        return _query_(left[nodeA], left[nodeB], ss, mid, qs, qe) + _query_(right[nodeA], right[nodeB], mid + 1, se, qs, qe);
    }

    T _query_(int nodeA, int nodeB, int ss, int se, int k)
    {
        if (ss == se)
            return ss;

        int diff = segTree[left[nodeA]] - segTree[left[nodeB]];
        int mid = (ss + se) / 2;

        if (diff >= k)
            return _query_(left[nodeA], left[nodeB], ss, mid, k);
        else
            return _query_(right[nodeA], right[nodeB], mid + 1, se, k - diff);
    }

    T query(int ul, int ur, int qs, int qe = -1)
    {
        if (qe == -1)
            return _query_(roots[ur], roots[ul - 1], 1, n, qs);
        else
            return _query_(roots[ur], roots[ul - 1], 1, n, qs, qe);
    }
};

void solve()
{
    cin >> n;

    PersistentSegmentTree<ll> segTree(n);

    REP(i, 1, n)
    {
        cin >> arr[i];
        mp[arr[i]];
    }

    for (auto &e : mp)
        e.second = ++timer;

    REP(i, 1, n)
    {
        int temp = arr[i];
        arr[i] = mp[arr[i]];
        rev[arr[i]] = temp;
        segTree.update(arr[i], 1);
    }

    cin >> q;

    REP(x, 1, q)
    {
        int i, j, k;
        cin >> i >> j >> k;
        k = bs(k) + 1;
        cout << segTree.query(i, j, k, n) << endl;
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