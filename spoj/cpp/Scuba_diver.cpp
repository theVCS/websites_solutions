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
#define INF 999999
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int oxy[1001], nitro[1001], wt[1001];
int t[1001][500][500];

int diver(int n, int oy, int ni)
{
    if (t[n][oy][ni] != -1)
    {
        return t[n][oy][ni];
    }
    else if (oy == 0 && ni == 0)
    {
        return t[n][oy][ni] = 0;
    }
    else if (n == 0)
    {
        return t[n][oy][ni] = INF;
    }
    else
    {
        return t[n][oy][ni] = min(wt[n - 1] + diver(n - 1, max(0, oy - oxy[n - 1]), max(0, ni - nitro[n - 1])), diver(n - 1, oy, ni));
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int te, nneed, oneed, n;

    cin >> te;

    while (te--)
    {
        memset(t, -1, sizeof(t));

        cin >> oneed >> nneed;

        cin >> n;

        REP(i, 0, n)
        cin >> oxy[i] >> nitro[i] >> wt[i];

        cout << diver(n, oneed, nneed) << endl;
    }

    return 0;
}