#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 5
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct fs
{
    int w, l, index;
} s[maxN];

bool cmp(fs a, fs b)
{
    return a.w < b.w;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        REP(i, 0, n)
        {
            cin >> s[i].w;
            s[i].index = i;
        }

        REP(i, 0, n)
        cin >> s[i].l;

        sort(s, s + n, cmp);

        int jumps = 0;

        REP(i, 1, n)
        {
            while (s[i].index <= s[i - 1].index)
            {
                s[i].index += s[i].l;
                jumps++;
            }
        }

        cout << jumps << endl;
    }

    return 0;
}