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

string s;

bool isValid(int k)
{
    int fre[4] = {0};

    REP(i, 0, k - 1)
    {
        fre[s[i] - '0']++;
    }

    REP(i, k - 1, s.size())
    {
        fre[s[i] - '0']++;

        if (fre[1] && fre[2] && fre[3])
            return true;

        // removing last element and adding first element
        fre[s[i - k + 1] - '0']--;
    }

    return false;
}

void solve()
{
    cin >> s;

    int start = 3, end = s.size(), ans = INT_MAX;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (isValid(mid))
            ans = min(ans, mid), end = mid - 1;
        else
            start = mid + 1;
    }

    cout << (ans == INT_MAX ? 0 : ans) << endl;
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