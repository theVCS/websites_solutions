#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define INF 0x3f3f3f3f
#define endl "\n"
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

int score(string s)
{
    if (s == "red")
        return 1;
    else if (s == "yellow")
        return 2;
    else if (s == "green")
        return 3;
    else if (s == "brown")
        return 4;
    else if (s == "blue")
        return 5;
    else if (s == "pink")
        return 6;
    else
        return 7;
}

int cnt[8];

void solve()
{
    int n, maxScore = 0;
    string s;

    cin >> n;

    REP(i, 0, n)
    {
        cin >> s;
        cnt[score(s)]++;
        maxScore = max(maxScore, score(s));
    }

    if(cnt[1] == n)
    {
        cout << 1 << endl;
    }
    else if (cnt[1])
    {
        int res = 0;

        REP(i, 2, maxScore)
        if (cnt[i])
            res += i;

        cout << cnt[1] + maxScore * (cnt[1] + 1) + res;
    }
    else
    {
        int res = 0;

        REP(i, 2, 8)
        if (cnt[i])
            res += i;

        cout << res;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}