#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 101
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

struct path
{
    int wgth;
    int n, m;
};

int arr[maxN][maxN];
bool use[maxN][maxN];
int res[maxN][maxN];
vector<path> pth;

bool cmp(path a, path b)
{
    return a.wgth < b.wgth;
}

void solve()
{
    int n, m, ele;
    cin >> n >> m;

    REP(i, 1, n)
    {
        REP(j, 1, m)
        {
            cin >> arr[i][j];
            path e;
            e.n = i, e.m = j, e.wgth = arr[i][j];
            pth.push_back(e);
        }
    }

    sort(all(pth), cmp);

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