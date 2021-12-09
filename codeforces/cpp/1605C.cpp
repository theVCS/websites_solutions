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

struct Data
{
    ll x, y, z;
} arr[maxN];

bool cmp(Data &a, Data &b)
{
    return a.z < b.z;
}

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
        BIT.assign(n + 1, 1e9);
    }

    T query(int index)
    {
        T q = INF;

        while (index > 0)
        {
            q = min(q, BIT[index]);
            index -= (index & -index);
        }

        return q;
    }

    void update(int index, T val)
    {
        while (index <= n)
        {
            BIT[index] = min(val, BIT[index]);
            index += (index & -index);
        }
    }
};

void solve()
{
    int n;
    string s;

    cin >> n;
    cin >> s;

    map<int, int> mp;

    int a = 0, b = 0, c = 0;

    int index = 1;

    for (char C : s)
    {
        if (C == 'a')
            a++;
        else if (C == 'b')
            b++;
        else
            c++;

        arr[index].x = a - b;
        arr[index].y = a - c;
        arr[index].z = index;
        mp[arr[index].y];
        index++;
    }

    sort(arr + 1, arr + 1 + n, cmp);

    int timer = 0;

    for (auto &e : mp)
        e.second = ++timer;

    REP(i, 1, n)
    arr[i].y = mp[arr[i].y];

    int ans = 0;
    FenwickTree<int> ft(timer+50);

    REP(i, 1, n)
    {
        // cout<<arr[i].x<<" "<<arr[i].y<<" "<<arr[i].z<<endl;
        int res = ft.query(arr[i].y + 1);
        ft.update(arr[i].y, arr[i].x);

        // cout << res << " ";

        if (res == INF)
            continue;

        ans = max(ans, i - res + 1);
    }

    if (ans == 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
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