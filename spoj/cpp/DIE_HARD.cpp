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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int cnt[1050][1050];

int maxSur(int h, int a, char curr = 'i')
{
    if (h <= 0 || a <= 0)
    {
        return 0;
    }
    else if (cnt[h][a] != -1)
    {
        return cnt[h][a];
    }
    if (curr == 'i')
    {
        return cnt[h][a] = max(maxSur(h, a, 'a'), maxSur(h, a, 'w'));
    }
    else if (curr == 'f' || curr == 'w')
    {
        return cnt[h][a] = 1 + maxSur(h + 3, a + 2, 'a');
    }
    else
    {
        return cnt[h][a] = max(1 + maxSur(h - 20, a + 5, 'f'), 1 + maxSur(h - 5, a - 10, 'w'));
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, h, a;

    cin >> t;

    while (t--)
    {
        memset(cnt, -1, sizeof(cnt));
        cin >> h >> a;
        cout << maxSur(h, a) - 1 << endl;
    }

    return 0;
}