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
int sz1, sz2;
vector<int> arr[2];

void solve()
{
    // 0 -> 0 0
    // 1 -> 0 1
    // 2 -> 1 0
    // 3 -> 1 1

    // 0 + 0 => 0
    // 0 + 1 => 1
    // 0 + 2 => 2
    // 1 + 2 => 0 3
    // 1 + 3 => 1
    // 2 + 3 => 2
    // 3 + 3 => 3

    cin >> n;
    string s;

    REP(i, 1, n)
    {
        cin >> s;
        int c1 = s.front() - 'B', c2 = s.back() - 'B';

        if (c1 == 0 && c2 == 0)
            sz1 += s.size();
        else if (c1 == 1 && c2 == 1)
            sz2 += s.size();
        else if (c1 == 0)
            arr[0].push_back(s.size());
        else
            arr[1].push_back(s.size());
    }

    int ans=0;
    
    sort(all(arr[0]));
    sort(all(arr[1]));
    
    int i = arr[0].size()-1;
    int j = arr[1].size()-1;

    while (i >= 0 && j >= 0)
    {
        ans += (arr[0][i]+arr[1][j]);
        i--,j--;
    }

    if(i>=0)ans+=arr[0][i];
    if(j>=0)ans+=arr[1][j];

    if(ans==0)
    {
        cout<<max(sz1,sz2);
        return;
    }

    cout<<ans+(sz1+sz2);
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