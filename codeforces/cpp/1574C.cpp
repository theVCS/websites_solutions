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

int n, m;
ll arr[maxN];
ll defense[maxN];
ll attack[maxN];
ll sum = 0;

int bs(ll p)
{
    int start = 1, end = n;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] >= p && (mid == start || arr[mid - 1] < p))
            return mid;
        else if (arr[mid] >= p)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

ll c1(int i)
{
    int index = bs(defense[i]);
    ll val = 0;

    if (index == -1)
    {
        val += defense[i] - arr[n];
        ll diff = sum - arr[n];

        if (diff < attack[i])
            val += attack[i] - diff;
    }
    else
    {
        ll diff = sum - arr[index];

        if (diff < attack[i])
            val += attack[i] - diff;
    }

    return val;
}

int bs1(ll v)
{
    int start = 1, end = n;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        ll diff = sum - arr[mid];

        if (diff >= v && (mid == end || sum - arr[mid + 1] < v))
        {
            return mid;
        }
        else if (diff >= v)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

ll c2(int i)
{
    ll val = 0;

    int index = bs1(attack[i]);

    if (index == -1)
    {
        val += attack[i] - (sum - arr[1]);
        ll diff = max(0LL, defense[i] - arr[1]);
        val += diff;
    }
    else
    {
        ll diff = max(0LL, defense[i] - arr[index]);
        val += diff;
    }

    return val;
}

void solve()
{

    cin >> n;

    REP(i, 1, n)
    cin >> arr[i], sum += arr[i];

    cin >> m;

    REP(i, 1, m)
    cin >> defense[i] >> attack[i];

    sort(arr + 1, arr + 1 + n);

    REP(i, 1, m)
    {
        // cout << c1(i) << " " << c2(i) << endl;
        cout<<min(c1(i),c2(i))<<endl;
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