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
#define maxN 10001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(4) << x
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
vector<point> strip, brr;

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

double bruteForce(int l, int r)
{
    double dis = INF;

    REP(i, l, r - 1)
    {
        REP(j, i + 1, r)
        {
            dis = min(dis, dist(arr[i], arr[j]));
        }
    }

    return dis;
}

double stripMinDist(double d)
{
    int sz = strip.size();
    // sort(all(strip), compareY);

    for (int i = 0; i < sz; i++)
    {
        for (int j = i + 1; j < sz && (strip[j].y - strip[i].y) < d; j++)
        {
            d = min(d, dist(strip[i], strip[j]));
        }
    }
    return d;
}

double minDis(int l, int r, vector<point> &availPoints)
{
    if (r - l + 1 <= 3)
        return bruteForce(l, r);

    int mid = (l + r) / 2;

    vector<point> lef, rig;

    for (point p : availPoints)
    {
        if (p.x <= arr[mid].x && lef.size() < (mid - l + 1))
            lef.push_back(p);
        else
            rig.push_back(p);
    }

    double d = minDis(l, mid, lef);
    d = min(d, minDis(mid + 1, r, rig));

    strip.clear();

    for (point p : availPoints)
    {
        if (abs(p.x - arr[mid].x) < d)
            strip.push_back(p);
    }

    return min(d, stripMinDist(d));
}

void solve()
{
    while (true)
    {
        cin >> n;

        if (n == 0)
        {
            return;
        }

        brr.clear();
        REP(i, 1, n)
        {
            cin >> arr[i].x >> arr[i].y;
            brr.push_back(arr[i]);
        }

        if (n <= 1)
        {
            cout << "INFINITY" << endl;
            continue;
        }

        sort(arr + 1, arr + 1 + n, compareX);
        sort(all(brr), compareY);

        double d = minDis(1, n, brr);

        if (d >= 10000)
        {
            cout << "INFINITY" << endl;
            continue;
        }

        printd(d) << endl;
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