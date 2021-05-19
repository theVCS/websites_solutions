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
#define maxN 100001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(6) << x << endl
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        power >>= 1;
    }
    return res;
}

int n, m, index;
int arr[maxN];
vector<double> vec;
double dp[maxN];

double fun(int index = 0)
{
    if (index == vec.size())
    {
        return 1;
    }
    else if(dp[index] > -1)
    {
        return dp[index];
    }
    else
    {
        return dp[index] = vec[index] * fun(index + 1) + (1 - vec[index]) * fun(index + 1);
    }
}

void solve()
{
    vec.clear();
    double d;
    double all_m = 1;
    int dum;

    cin >> n >> m;

    REP(i, 1, n)
    cin >> arr[i];

    arr[0] = -1;
    index = 0;

    RREP(i, n, 1)
    {
        if (arr[i] != i)
        {
            index = i;
            break;
        }
    }

    REP(i, 1, m)
    {
        cin >> dum;
        cin >> d;

        if (dum >= index)
        {
            vec.push_back(d);
            all_m *= (1 - d);
        }

        dp[i] = -1;
    }

    dp[0] = -1;

    if (index == 0)
    {
        printd(double(1));
        return;
    }

    printd(fun() - all_m);
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