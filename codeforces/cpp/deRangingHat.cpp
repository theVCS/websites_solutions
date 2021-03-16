#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1001
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

struct info
{
    char ch;
    int prevIndex;
} dat[maxN];

bool cmp(info a, info b)
{
    return a.ch < b.ch;
}
vector<pii> index;
int newIndex[maxN];

void solve()
{
    string s;

    cin >> s;

    int n = s.size();

    REP(i, 0, n)
    {
        dat[i].ch = s[i];
        dat[i].prevIndex = i;
    }

    sort(dat, dat + n, cmp);

    REP(i, 0, n)
    {
        newIndex[dat[i].prevIndex] = i;
    }

    REP(i, 0, n)
    {
        if (dat[i].ch != s[i])
        {
            if (s[i] > s[dat[i].prevIndex])
                cout << dat[i].prevIndex + 1 << " " << i + 1 << endl;
            else
                cout << i + 1 << " " << dat[i].prevIndex + 1 << endl;

            swap(s[i], s[dat[i].prevIndex]);
            swap(dat[i].prevIndex, dat[newIndex[i]].prevIndex);
        }
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