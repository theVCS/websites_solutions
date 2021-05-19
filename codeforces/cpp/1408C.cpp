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
#define printd(x) cout << fixed << setprecision(6) << x
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

int arr[maxN];

void solve()
{
    int n, l;
    cin >> n >> l;

    REP(i, 1, n)
    cin >> arr[i];

    double carpos1 = 0, carpos2 = l;
    int carspe1 = 1, carspe2 = 1;
    double timer = 0;
    int r = n;
    l = 1;

    while (l <= r)
    {
        double t1 = (1.0 * (arr[l] - carpos1)) / carspe1;
        double t2 = (1.0 * (carpos2 - arr[r])) / carspe2;

        if (t1 == t2)
        {
            carspe1++, carspe2++;
            carpos1 = arr[l];
            carpos2 = arr[r];
            l++, r--;
            timer += t1;
        }
        else if (t2 < t1)
        {
            carspe2++;
            carpos2 = arr[r];
            carpos1 += carspe1 * t2;
            r--;
            timer += t2;
        }
        else
        {
            carspe1++;
            carpos1 = arr[l];
            carpos2 -= carspe2 * t1;
            l++;
            timer += t1;
        }
    }

    timer += (1.0 * (carpos2 - carpos1)) / (carspe1 + carspe2);
    printd(timer) << endl;
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