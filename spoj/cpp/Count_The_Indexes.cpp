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

int q;
vector<int> vec[200001];
int arr[200001];

void solve()
{
    cin >> q;
    int index = 0;

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 0)
        {
            if (index == 0)
                cout << "invalid" << endl;
            else
            {
                vec[arr[index]].pop_back();
                index--;
            }
        }
        else if (type == 1)
        {
            cin >> arr[++index];
            vec[arr[index]].push_back(index);
        }
        else
        {
            int x, i, j;
            cin >> x >> i >> j;

            if (vec[x].size())
            {
                int cnt = upper_bound(all(vec[x]), j) - lower_bound(all(vec[x]), i);
                cout << cnt << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
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