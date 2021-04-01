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
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int sum(int n)
{
    return (n * (n + 1)) / 2;
}

vector<int>res;

void dp(int sum, int nTerm = 1)
{
    if(2 * nTerm + 1 <= sum)
    {
        res.push_back(nTerm);
        dp(sum - nTerm, nTerm + 1);
    }
    else
    {
        res.push_back(sum);
    }
}

void solve()
{
    int n;

    cin >> n;

    // int x = (-1 + sqrt(8*n+1)) / 2;
    
    // cout << x << endl;

    // REP(i,1,x)cout << i << " ";
    // cout << n - sum(x - 1);

    dp(n);

    cout << res.size() << endl;

    for(int e: res)cout << e << " ";
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