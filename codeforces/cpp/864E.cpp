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

int n;

struct item
{
    int ti, di, price, index;
} arr[101];

bool cmp(item &a, item &b)
{
    return a.di < b.di;
}

int dp[101][2001];

int maxPrice(int pos = 1, int t = 0)
{
    if (pos == n + 1)
        return 0;
    else if (dp[pos][t] != -1)
        return dp[pos][t];
    else if (arr[pos].di > t + arr[pos].ti)
        return dp[pos][t] = max(arr[pos].price + maxPrice(pos + 1, t + arr[pos].ti), maxPrice(pos + 1, t));
    else
        return dp[pos][t] = maxPrice(pos + 1, t);
}

vector<int> res;

void getProduct(int pos = 1, int t = 0)
{
    if (pos == n + 1)
        return;
    else if (arr[pos].di > t + arr[pos].ti)
    {
        if (arr[pos].price + maxPrice(pos + 1, t + arr[pos].ti) > maxPrice(pos + 1, t))
        {
            res.push_back(arr[pos].index);
            getProduct(pos + 1, t + arr[pos].ti);
        }
        else
            getProduct(pos + 1, t);
    }
    else
        getProduct(pos + 1, t);
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    cin >> arr[i].ti >> arr[i].di >> arr[i].price, arr[i].index = i;

    sort(arr + 1, arr + 1 + n, cmp);
    memset(dp, -1, sizeof(dp));

    cout << maxPrice() << endl;
    getProduct();

    cout << res.size() << endl;
    for (int i : res)
        cout << i << " ";
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