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

deque<int> val[maxN];

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
            q = max(q, BIT[index]);
            index -= (index & -index);
        }

        return q;
    }

    void update(int index, T val)
    {
        while (index <= n)
        {
            BIT[index] = max(BIT[index], val);
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

// size of object b
const int sz = 1001;
int dp[sz][sz];

// caution --- for numbers use vector starting at index 0 and for characters use string
template <class T>
class LongestCommonSubsequence
{
    T a, b;

public:
    LongestCommonSubsequence(T &A, T &B)
    {
        a = A, b = B;
    }

    // returns length of longest common subsequence (memory efficient)
    // convert dp[sz][sz] => dp[2][sz];
    int lcsLengthMemoryEfficient()
    {
        int n = a.size();
        int m = b.size();

        REP(i, 0, m)
        dp[i][0] = dp[i][1] = 0;

        REP(i, 1, n)
        REP(j, 1, m)
        {
            int p = (i & 1);

            if (a[i - 1] == b[j - 1])
                dp[p][j] = 1 + dp[p ^ 1][j - 1];
            else
                dp[p][j] = max(dp[p ^ 1][j], dp[p][j - 1]);
        }

        return dp[n & 1][m];
    }

    int lcsLength()
    {
        int n = a.size();
        int m = b.size();

        REP(i, 0, n)
        dp[i][0] = 0;
        REP(j, 0, m)
        dp[0][j] = 0;

        REP(i, 1, n)
        REP(j, 1, m)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

        return dp[n][m];
    }

    void printSuperSubsequence()
    {
        T res;

        int i = a.size();
        int j = b.size();

        while (i && j)
        {
            if (a[i - 1] == b[j - 1])
                res.push_back(a[i - 1]), i--, j--;
            else if (dp[i - 1][j] > dp[i][j - 1])
                res.push_back(a[i - 1]), i--;
            else
                res.push_back(b[j - 1]), j--;
        }

        while (i)
            res.push_back(a[i - 1]), i--;
        while (j)
            res.push_back(b[j - 1]), j--;

        reverse(all(res));

        for (auto e : res)
            cout << e << " ";
        cout << endl;
    }

    void printLCS()
    {
        T res;

        int i = a.size();
        int j = b.size();

        while (i && j)
        {
            if (a[i - 1] == b[j - 1])
                res.push_back(a[i - 1]), i--, j--;
            else if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }

        reverse(all(res));
        for (auto e : res)
            cout << e << " ";
        cout << endl;
    }
};

void solve()
{
    int n, l;
    cin >> n >> l;

    REP(i, 1, n)
    {
        int x;
        cin >> x;
        val[x].push_back(i);
    }

    FenwickTree<int> ft(n);
    int ans = 0;

    REP(i, 1, n)
    {
        int x;
        cin >> x;
        int y = val[x].front();
        val[x].pop_front();
        int res = ft.query(y);
        ft.update(y, res + 1);
        ans = max(ans, res);
    }

    ans++;
    cout << 2 * (n - ans) << endl;
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