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
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll a[maxN], t[maxN];
ll prefixSum[maxN];
ll conOne[maxN];

void solve()
{
    ll n, k;
    cin >> n >> k;

    REP(i, 1, n + 1)
    {
        cin >> a[i];
        prefixSum[i] = a[i] + prefixSum[i-1];
    }

    int co = 0;

    REP(i, 1, n + 1)
    {
        conOne[i] = co;
        cin >> t[i];
        if (t[i])
            co++;
        else
            co = 0;
    }

    int res = 0;

    REP(i, 1, n - k + 2)
    {
        int preSum = prefixSum[i - 1] - prefixSum[i - conOne[i] - 1];
        int postSum = prefixSum[i + k - 1] - prefixSum[i - 1];
        res = max(res, preSum + postSum);
    }
    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream filptr("input.txt");
    // ofstream outpter("output.txt");

    // filptr >> input;
    // outpter << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}