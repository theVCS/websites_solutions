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

int n;
vector<int> arr[maxN];
int val[maxN];

int weight(int i, int j)
{
    if (val[i] > val[j])
        return 1;
    else if (val[i] < val[j])
        return -1;
    return 0;
}

ll ans;
ll incNode[maxN];
ll decNode[maxN];

void dfs(int node = 1, int par = -1)
{
    vector<ll>inc, dec;
    ll sinc=0,sdec=0;

    for (int child : arr[node])
    {
        if (child == par)
            continue;

        dfs(child, node);

        int w = weight(node, child);

        if (w == 1)
        {
            incNode[node] += incNode[child];
            inc.push_back(incNode[child]);
            sinc+=incNode[child];
        }
        else if (w == -1)
        {
            decNode[node] += decNode[child];
            dec.push_back(decNode[child]);
            sdec+=decNode[child];
        }
    }

    incNode[node]++;
    decNode[node]++;

    sinc++;
    sdec++;
    // dec.push_back(1);
    // inc.push_back(1);

    ll path=0;

    for(ll e: inc)
        path+=e*(sinc-e);

    for(ll e: dec)
        path+=e*(sdec-e);

    ans += path+sinc*sdec;
}

void solve()
{
    ans = 0;

    cin >> n;

    REP(i, 1, n)
    {
        arr[i].clear();
        cin >> val[i];
        incNode[i]=decNode[i]=0;
        // con_none[i] = con_one[i] = 0;
        // con_none[i] = con_one[i] = justOneOne[i] = justOneZero[i] = 0;
    }

    REP(i, 1, n - 1)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    dfs();

    cout << ans/2 << endl;
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