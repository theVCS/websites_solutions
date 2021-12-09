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

int n;

struct Data
{
    int a, index, cor;
} arr[maxN];

bool cmp(Data &a, Data &b)
{
    return a.a > b.a;
}

int ans[maxN];

void solve()
{
    cin >> n;

    arr[0].a = arr[0].index = arr[0].cor = 0;

    REP(i, 1, n)
    {
        cin >> arr[i].a;
        arr[i].index = i;
    }

    sort(arr + 1, arr + 1 + n, cmp);

    ll res = 0;
    ll cor = 1;

    REP(i, 1, n)
    {
        res += 2 * arr[i].a * abs(cor);
        ans[arr[i].index] = cor;
        
        if (i % 2)
            cor *= -1;
        else
            cor--, cor *= -1;
    }

    cout << res << endl;
    cout << 0 << " ";
    REP(i, 1, n)
        cout << ans[i] << " ";
    cout << endl;
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