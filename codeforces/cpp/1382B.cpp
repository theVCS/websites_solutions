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

int arr[maxN];
bool dp[maxN];
int n;

bool fun(int index, int player = 0)
{
    if (index == n)
    {
        return (player == 0);
    }
    else if (index > n)
    {
        return false;
    }
    else if (arr[index] == 1)
    {
        return fun(index + 1, (player + 1) % 2);
    }
    else
    {
        return (player == 0);
    }
}

void solve()
{
    cin >> n;

    REP(i, 1, n + 1)
    cin >> arr[i];

    if (fun(1))
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
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

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}