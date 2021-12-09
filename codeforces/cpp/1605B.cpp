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

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    int one = 0, zero = 0;

    for (char c : s)
    {
        if (c == '0')
            zero++;
        else
            one++;
    }

    vector<int> ind;

    REP(i, 0, n - 1)
    {
        if (s[i] == '0')
        {
            if (i >= zero)
                ind.push_back(i + 1);
        }
        else
        {
            if (i < zero)
                ind.push_back(i + 1);
        }
    }

    if (ind.size())
    {
        cout << 1 << endl;
        cout << ind.size() << " ";

        for (int i : ind)
            cout << i << " ";
        cout << endl;
    }
    else
        cout << 0 << endl;
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