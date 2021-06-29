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

int n;
struct point
{
    ll x, y;
} arr[maxN];
vector<point> strip;

bool compareX(point a, point b)
{
    return a.x < b.x;
}

bool compareY(point a, point b)
{
    return a.y < b.y;
}

double dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double minStripDis()
{
    // sort(all(strip), compareY);
    int sz = strip.size();
    double d = INF;

    for (int i = 0; i < sz; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            for (int k = j + 1; k < sz; k++)
            {
                double dis = dist(strip[i], strip[j]) + dist(strip[j], strip[k]) + dist(strip[k], strip[i]);
                d = min(dis, d);
            }
        }
    }

    return d;
}

double minDis(int l, int r)
{
    if (r - l < 2)
    {
        return INF;
    }

    if (r - l == 2)
    {
        return dist(arr[l], arr[l + 1]) + dist(arr[l + 1], arr[r]) + dist(arr[r], arr[l]);
    }

    int mid = (l + r) / 2;
    double d = minDis(l, mid);
    d = min(minDis(mid + 1, r), d);

    strip.clear();

    REP(i, l, r)
    {
        if (abs(arr[i].x - arr[mid].x) < (d / 2.0))
        {
            strip.push_back(arr[i]);
        }
    }

    return min(d, minStripDis());
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr + 1, arr + 1 + n, compareX);
    printd(minDis(1, n)) << endl;
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

    REP(i,1,t)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}