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
class FenwickTree
{
    int n, LOGN;
    vector<T> BIT;

public:
    FenwickTree() {}

    FenwickTree(int N)
    {
        LOGN = log2(N);
        n = N;
        BIT.assign(n + 1, 0);
    }

    void resize(int N)
    {
        LOGN = log2(N);
        n = N;
        BIT.assign(n + 1, 0);
    }

    T query(int index)
    {
        T q = 0;

        while (index > 0)
        {
            q += BIT[index];
            index -= (index & -index);
        }

        return q;
    }

    void update(int index, T val)
    {
        while (index <= n)
        {
            BIT[index] += val;
            index += (index & -index);
        }
    }

    T query(int l, int r)
    {
        return query(r) - query(l - 1);
    }

    void update(int l, int r, int val)
    {
        update(l, val);
        update(r + 1, -val);
    }

    int lowerBound(T val)
    {
        // will find the lower bound index of val in BIT if monotonically increasing
        // https://codeforces.com/blog/entry/61364

        T q = 0;
        int pos = 0;

        for (int i = LOGN; i >= 0; i--)
        {
            if (pos + (1 << i) <= n && q + BIT[pos + (1 << i)] < val)
            {
                q += BIT[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        return pos + 1;
    }
};
FenwickTree<int> bit(100000);

int n;
struct Point
{
    int x, y, z, index;
} arr[maxN];

bool cmp(Point &a, Point &b)
{
    if (a.x != b.x)
        return a.x > b.x;
    else if (a.y != b.y)
        return a.y < b.y;
    else
        return a.z > b.z;
}

int ans[maxN];

void cdq(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    cdq(l, mid), cdq(mid + 1, r);

    vector<Point> temp;
    vector<int> cha;

    int a = l, b = mid + 1, s = 0;

    while (a <= mid && b <= r)
    {
        if (arr[a].y > arr[b].y)
            bit.update(arr[a].z, 1), cha.push_back(arr[a].z), s++, temp.push_back(arr[a]), a++;
        else
            ans[arr[b].index] += s - bit.query(arr[b].z), temp.push_back(arr[b]), b++;
    }

    while (a <= mid)
    {
        temp.push_back(arr[a++]);
    }

    while (b <= r)
    {
        ans[arr[b].index] += s - bit.query(arr[b].z);
        temp.push_back(arr[b++]);
    }

    for (int i : cha)
        bit.update(i, -1);

    REP(i, l, r)
    arr[i] = temp[i - l];
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    cin >> arr[i].x >> arr[i].y >> arr[i].z, arr[i].index = i;

    sort(arr + 1, arr + 1 + n, cmp);
    cdq(1, n);

    REP(i, 1, n)
    cout << ans[i] << endl;
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