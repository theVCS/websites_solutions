#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 10001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct order
{
    ll start, end;
    ll cost;
} arr[maxN];
int n;

bool cmp(order &a, order &b)
{
    if (a.end == b.end)
        return a.start < b.start;
    else
        return a.end < b.end;
}

int bs(int val)
{
    int start = 1, end = n;

    while (start<=end)
    {
        int mid = (start+end)/2;

        if(arr[mid].end<=val && (mid==end || arr[mid+1].end>val))
            return mid;
        else if(arr[mid].end<=val)
            start=mid+1;
        else end=mid-1;
    }
    return 0;
}

int dp[maxN];

ll fun(int index)
{
    if (index <= 0)
        return 0;
    else if(dp[index]!=-1)
        return dp[index];
    else
    {
        int newIndex = bs(arr[index].start);
        return dp[index] = max(arr[index].cost + fun(newIndex), fun(index - 1));
    }
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i].start >> arr[i].end >> arr[i].cost;
        dp[i] = -1;
        arr[i].end+=arr[i].start;
    }

    sort(arr + 1, arr + 1 + n, cmp);

    cout<<fun(n)<<endl;
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