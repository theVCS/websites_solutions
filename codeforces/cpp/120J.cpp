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
#define printd(x) cout << fixed << setprecision(10) << x
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
    ll x, y, index;
} old[maxN], arr[maxN];
vector<point> strip;

bool compareX(point a, point b)
{
    return a.x < b.x;
}

bool compareY(point a, point b)
{
    return a.y < b.y;
}

struct ans
{
    int i, j;
    double dis;
};

ans minimum(ans a, ans b)
{
    if (a.dis < b.dis)
        return a;
    else
        return b;
}

double dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ans bruteForce(int l, int r)
{
    ans res;
    res.dis = INF;

    REP(i, l, r - 1)
    {
        REP(j, i + 1, r)
        {
            double d = dist(arr[i], arr[j]);

            if (d < res.dis)
            {
                res.dis = d;
                res.i = i;
                res.j = j;
            }
        }
    }

    return res;
}

ans minStripDis(double d)
{
    ans res;
    res.dis = d;
    res.i = res.j = -1;

    sort(all(strip), compareY);
    int sz = strip.size();

    for (int i = 0; i < sz; i++)
    {
        for (int j = i + 1; j < sz && (strip[j].y - strip[i].y) < d; j++)
        {
            double dis = dist(strip[i], strip[j]);

            if (d > dis)
            {
                d = dis;
                res.i = i;
                res.j = j;
                res.dis = d;
            }
        }
    }

    if (res.i == -1 || res.j == -1)
        res.dis = INF;
    else
        res.i = strip[res.i].index, res.j = strip[res.j].index;

    return res;
}

ans minDis(int l, int r)
{
    if ((r - l + 1) <= 3)
        return bruteForce(l, r);

    int mid = (l + r) / 2;
    ans d = minDis(l, mid);
    d = minimum(d, minDis(mid + 1, r));

    strip.clear();

    REP(i, l, r)
    {
        if (abs(arr[i].x - arr[mid].x) < d.dis)
            strip.push_back(arr[i]), strip.back().index = i;
    }

    return minimum(d, minStripDis(d.dis));
}

int kFinderPos(point old)
{
    if(old.x < 0 && old.y < 0)
        return 4;
    else if (old.y < 0)
        return 3;
    else if(old.x < 0)
        return 2;
    else return 1;
}

int kFinderNeg(point old)
{
    if(old.x > 0 && old.y > 0)
        return 4;
    else if (old.y > 0)
        return 3;
    else if(old.x > 0)
        return 2;
    else return 1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ifstream filptr("input.txt");
    ofstream outpter("output.txt");

    filptr >> n;

    REP(i, 1, n)
    {
        filptr >> old[i].x >> old[i].y;
        arr[i].x = abs(old[i].x);
        arr[i].y = abs(old[i].y);
        arr[i].index = i;

        // cout<<arr[i].x<<" "<<arr[i].y<<endl;
    }

    sort(arr + 1, arr + 1 + n, compareX);

    ans res = minDis(1, n);
    
    res.i = arr[res.i].index;
    res.j = arr[res.j].index;

    outpter<<res.i<<" "<<kFinderPos(old[res.i])<<" "<<res.j<<" "<<kFinderNeg(old[res.j]);

    filptr.close();
    outpter.close();

    return 0;
}