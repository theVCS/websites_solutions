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

int cnt[maxN];

void solve()
{
    string s;
    cin >> s;

    int m, l, r;
    cin >> m;

    REP(i,0,s.size() - 1)
    {
        if(s[i] == s[i + 1])cnt[i]=1;
    }

    REP(i,1,s.size())
    {
        cnt[i]+=cnt[i-1];
    }

    // REP(i,0,s.size())cout << cnt[i] << " ";
    // cout << endl;

    REP(i,0,m)
    {
        cin>>l>>r;
        int res = cnt[r - 2];

        if(l > 1)
        {
            res -= cnt[l - 2];
        }

        cout << res << endl;
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