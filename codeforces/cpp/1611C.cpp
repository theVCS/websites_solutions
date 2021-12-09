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
int arr[maxN];
int res[maxN];
deque<int> d;

void solve()
{
    d.clear();

    cin >> n;
    REP(i, 1, n)
    cin >> arr[i];

    if(max(arr[1], arr[n])!=n)
    {
        cout<<-1<<endl;
        return;
    }

    int i = 1, j = n;

    while (i <= j)
    {
        if (arr[i] > arr[j])
            d.push_front(arr[i++]);
        else
            d.push_back(arr[j--]);
    }

    int index = 1;

    while (d.empty() == false)
    {
        res[index++] = d.front();
        d.pop_front();
        cout<<res[index-1]<<" ";
    }

    cout<<endl;

    // i = 1, j = n;

    // while (i <= j)
    // {
    //     if (res[i] > res[j])
    //         d.push_back(res[j--]);
    //     else
    //         d.push_back(res[i++]);
    // }

    // index = 1;

    // while (d.empty() == false)
    // {
    //     if (arr[index++] != d.front())
    //     {
    //         cout << -1 << endl;
    //         return;
    //     }
    //     d.pop_front();
    // }

    // REP(i, 1, n)
    // cout << res[i] << " ";
    // cout << endl;
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