#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000011
#define INF 1000000000
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

string s, res;
int n, cnt[maxN][26];
set<pair<char, int>> charSet[maxN];
int use[26];

void solve()
{
    cin >> s;

    n = s.size();

    REP(i, 0, 26)
    use[i] = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        use[s[i] - 'a'] = 0;
        charSet[i].clear();

        for (pair<char, int> c : charSet[i + 1])
            charSet[i].insert(c);

        REP(j, 0, 26)
        {
            cnt[i][j] = 0;
            cnt[i][j] += cnt[i + 1][j];
        }

        cnt[i][s[i] - 'a']++;
        charSet[i].insert({s[i], i});
    }

    int index = 0;
    cout << res << endl;

    while (index < n)
    {
        for (int i = 25; i >= 0; i--)
        {
            if (charSet[index + 1].find(char(i + 'a')) == charSet[index + 1].end())
            {
                continue;
            }

            REP(i, 0, 26)
            {
                if (use[i] == 0 && cnt[index + 1][i])
                {
                }
            }
        }

        index++;
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

    cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}