#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 5000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int sieve[maxN];

void sieveFactors()
{
    for (int i = 2; i < maxN; i++)
    {
        if (!sieve[i])
        {
            for (int j = i; j < maxN; j += i)
            {
                if (!sieve[j])
                {
                    sieve[j] = i;
                }
            }
        }
    }
}

set<int> cnt[5001];

void add(int n)
{
    int _number = n;

    while (sieve[_number])
    {
        cnt[sieve[_number]].insert(n);
        _number = _number / sieve[_number];
    }
}

int find(int val)
{
    int _number = val;
    int mx = 1;

    while (sieve[_number])
    {
        for (int num : cnt[sieve[_number]])
        {
            int g = __gcd(num, val);
            mx = max(mx,g);
        }

        _number = _number / sieve[_number];
        cnt[sieve[_number]].erase(val);
    }

    return mx;
}

ll ans = 0;
int arr[maxN];

void solve()
{
    int n;
    cin >> n;
    int mx = 0;

    REP(i, 1, n)
    {
        cin >> arr[i];
        add(arr[i]);
        mx = max(mx, arr[i]);
    }

    ll res = mx;

    REP(i, 1, n)
    {
        mx = find(mx);

        if (mx == 1)
        {
            res += (n - i + 1);
            break;
        }
        else
            res += mx;
    }

    cout << res;
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