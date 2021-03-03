#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 111
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

bool vis[maxN];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        int n;
        string s;

        cin >> n >> s;

        memset(vis, false, maxN);

        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '*')
                vis[i - 1] = vis[i] = vis[i + 1] = true;
        }

        int cnt = 0;
        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == true)
            {
                res += ceil(cnt * 1.0 / 3);
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }

        if (vis[n] == false)
            res += ceil(cnt * 1.0 / 3);

        cout << res << endl;
    }

    return 0;
}