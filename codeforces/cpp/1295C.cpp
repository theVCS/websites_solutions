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

string s, t;
vector<int> index[26];

int bs(int alp, int ind)
{
    // cout<<alp<<" "<<ind<<endl;
    int start = 0, end = index[alp].size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (index[alp][mid] > ind && (mid == start || index[alp][mid - 1] <= ind))
            return index[alp][mid];
        else if (index[alp][mid] > ind)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

void solve()
{
    REP(i, 0, 25)
    index[i].clear();

    cin >> s >> t;

    REP(i, 0, s.size() - 1)
    {
        index[s[i] - 'a'].push_back(i);
    }

    int ans = 1;
    int ind = -1;

    for (char &c : t)
    {
        if (index[c - 'a'].size() == 0)
        {
            cout << -1 << endl;
            return;
        }

        ind = bs(c - 'a', ind);
        // cout<<ind<<" "<<ans<<endl;

        if (ind == -1)
        {
            ans++;
            ind = bs(c - 'a', ind);
        }
    }
    
    cout << ans << endl;
    // cout<<bs(24,-1)<<endl;
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