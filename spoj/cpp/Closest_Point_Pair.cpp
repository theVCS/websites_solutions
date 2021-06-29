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
#define maxN 50001
#define endl "\n"
#define INF 1000000000000
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
    int index;
} arr[maxN];
vector<point> strip;

struct ans
{
    int i, j;
    double dist;
} res;

ans minimum(ans a, ans b)
{
    if (a.dist < b.dist)
        return a;
    else
        return b;
}

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

ans bruteForce(int l, int r)
{
    double d = INF;
    int _i = 0, _j = 0;

    REP(i, l, r - 1)
    {
        REP(j, i + 1, r)
        {
            double di = dist(arr[i], arr[j]);

            if (d > di)
            {
                d = di, _i = i, _j = j;
            }
        }
    }

    ans res;
    res.i = _i;
    res.j = _j;
    res.dist = d;

    return res;
}

ans stripMinDis(ans d)
{
    int sz = strip.size();
    sort(all(strip), compareY);

    bool flag = true;

    for (int i = 0; i < sz; i++)
    {
        for (int j = i + 1; j < sz && (strip[j].y - strip[i].y) < d.dist; j++)
        {
            double dis = dist(strip[i], strip[j]);

            if (dis < d.dist)
            {
                d.dist = dis;
                d.i = i;
                d.j = j;
                flag = false;
            }
        }
    }

    if (flag)
        d.dist = INF;
    else
    {
        d.i = strip[d.i].index;
        d.j = strip[d.j].index;
    }

    return d;
}

ans minDis(int l, int r)
{
    if (r - l + 1 <= 3)
        return bruteForce(l, r);

    int mid = (l + r) / 2;
    ans d = minDis(l, mid);
    d = minimum(d, minDis(mid + 1, r));

    strip.clear();

    REP(i, l, r)
    {
        if (abs(arr[i].x - arr[mid].x) < d.dist)
        {
            strip.push_back(arr[i]), strip.back().index = i;
        }
    }

    return minimum(d, stripMinDis(d));
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i].x >> arr[i].y;
        arr[i].index = i;
    }

    sort(arr + 1, arr + 1 + n, compareX);

    ans e = minDis(1, n);

    cout << min(arr[e.i].index,arr[e.j].index) - 1 << " " << max(arr[e.i].index,arr[e.j].index) - 1 << " ";
    printd(e.dist);
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