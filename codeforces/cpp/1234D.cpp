#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

string s;
int segTree[maxN * 4][26];
int cnt[26], ans;

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si][s[ss] - 'a'] = 1;
    }
    else
    {
        int mid = (ss + se) / 2;

        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);

        REP(i, 0, 26)
        {
            segTree[si][i] = segTree[2 * si][i] + segTree[2 * si + 1][i];
        }
    }
}

void query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return;

    if (qs <= ss && qe >= se)
    {
        REP(i, 0, 26)
        cnt[i] += segTree[si][i];

        return;
    }

    int mid = (ss + se) / 2;
    query(2 * si, ss, mid, qs, qe);
    query(2 * si + 1, mid + 1, se, qs, qe);
}

void update(int si, int ss, int se, int qi, char c)
{
    if (ss == se)
    {
        // removing old character
        segTree[si][s[ss] - 'a'] = 0;

        s[ss] = c;

        // replacing new character as c
        segTree[si][c - 'a'] = 1;

        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
    {
        update(2 * si, ss, mid, qi, c);
    }
    else
    {
        update(2 * si + 1, mid + 1, se, qi, c);
    }

    REP(i, 0, 26)
    segTree[si][i] = segTree[2 * si][i] + segTree[2 * si + 1][i];
}

void printer()
{
    REP(i, 0, 26)
    cout << char('a' + i) << " -> " << segTree[1][i] << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    int n = s.size();
    int m, code, a, b;
    char c;

    s.insert(0, "0");

    build(1, 1, n);

    cin >> m;

    while (m--)
    {
        cin >> code;

        if (code == 1)
        {
            //s[a]= c
            cin >> a >> c;
            update(1, 1, n, a, c);
            // printer();
        }
        else
        {
            // distinct characters in [a,b];
            ans = 0;

            cin >> a >> b;

            query(1, 1, n, a, b);

            REP(i, 0, 26)
            {
                if (cnt[i])
                    ans++;
                
                cnt[i] = 0;
            }

            cout << ans << endl;
        }
    }

    return 0;
}