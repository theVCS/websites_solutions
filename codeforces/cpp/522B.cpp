#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200011
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll width[maxN];
ll height[maxN];
ll prefix[maxN];
ll suffix[maxN];

void solve()
{
    int n;
    cin >> n;
    ll tot_width = 0;

    REP(i,1,n+1)
    {
        cin >> width[i] >> height[i];
        tot_width += width[i];
    }

    REP(i,1,n+1)prefix[i] = max(prefix[i - 1], height[i]);
    for(int i = n;i >= 1; i--)suffix[i] = max(suffix[i + 1], height[i]);

    REP(i,1,n+1)
    {
        ll w = tot_width - width[i];
        ll h = max(prefix[i - 1], suffix[i + 1]);
        cout << w * h << " ";
    }
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