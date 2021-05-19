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
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 1};
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

int n;
int arr[5001];
vector<int> person, empty_seats;
ll dp[2501][5001];

ll fun(int per_size, int seat_size)
{
    // cout<<per_size<<" "<<seat_size<<endl;
    if (per_size == 0)
    {
        return 0;
    }
    else if (dp[per_size][seat_size] != -1)
    {
        return dp[per_size][seat_size];   
    }
    else if (per_size < seat_size)
    {
        return dp[per_size][seat_size] = min(abs(person[per_size - 1] - empty_seats[seat_size - 1]) + fun(per_size - 1, seat_size - 1), fun(per_size, seat_size - 1));
    }
    else
    {
        return dp[per_size][seat_size] = abs(person[per_size - 1] - empty_seats[seat_size - 1]) + fun(per_size - 1, seat_size - 1);
    }
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i];

        if (arr[i])
        {
            person.push_back(i);
        }
        else
        {
            empty_seats.push_back(i);
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << fun(person.size(), empty_seats.size());
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