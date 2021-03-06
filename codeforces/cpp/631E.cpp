#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

struct point
{
    ll x, y, z;
    int index;

    point(long long tmp_x = 0, long long tmp_y = 0, long long tmp_z = 0)
    {
        x = tmp_x;
        y = tmp_y;
        z = tmp_z;
    }

    point operator+(point b)
    {
        return point(this->x + b.x, this->y + b.y, this->z + b.z);
    }

    point operator-(point b)
    {
        return point(this->x - b.x, this->y - b.y, this->z - b.z);
    }

    point operator*(long long val)
    {
        return point(this->x * val, this->y * val, this->z * val);
    }

    point operator/(long long val)
    {
        return point(this->x / val, this->y / val, this->z / val);
    }

    point &operator=(point b)
    {
        this->x = b.x;
        this->y = b.y;
        this->z = b.z;
        return *this;
    }

    point &operator+=(point b)
    {
        *this = *this + b;
        return *this;
    }

    point &operator-=(point b)
    {
        *this = *this - b;
        return *this;
    }

    point &operator*=(long long val)
    {
        (*this) = (*this) * val;
        return *this;
    }

    point &operator/=(long long val)
    {
        (*this) = (*this) / val;
        return *this;
    }

    bool operator==(point b)
    {
        if (this->x == b.x && this->y == b.y && this->z == b.z)
            return true;
        else
            return false;
    }
};
vector<point> points;

ll dot(point a, point b)
{
    ll ans = a.x * b.x + a.y * b.y + a.z * b.z;
    return ans;
}

point cross(point a, point b)
{
    point e;
    e.x = a.y * b.z - b.y * a.z;
    e.y = a.z * b.x - b.z * a.x;
    e.z = a.x * b.y - b.x * a.y;
    return e;
}

double magnitude(point a)
{
    return sqrt(dot(a, a));
}

double ang(point a, point b)
{
    return acos(dot(a, b) / (magnitude(a) * magnitude(b)));
}

double rad_to_deg(double val)
{
    return val * 180 / pi;
}

double deg_to_rad(double val)
{
    return val * pi / 180;
}

int direction(point pivot, point a, point b)
{
    long long t = cross((a - pivot), (b - pivot)).z;

    // t > 0, a x b is anti clockwise
    // t < 0, a x b is clockwise
    // t == 0, a and b are collinear

    return t;
}

#define maxN 200001
#define INF 1000000000000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
#define printpoint(p) cout << p.x << " " << p.y << " " << p.z
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
ll arr[maxN];

struct line
{
    ll slope, yIntercept;

    line(ll s = 0, ll y = -INF)
    {
        slope = s;
        yIntercept = y;
    }

    ll f(ll x)
    {
        return slope * x + yIntercept;
    }
};

line segTree[4 * 2000001];
line segTree2[4 * 2000001];

void update(int si, int ss, int se, line l)
{
    int mid = (ss + se) / 2;
    bool f1 = segTree[si].f(ss - 1000001) < l.f(ss - 1000001);
    bool f2 = segTree[si].f(mid - 1000001) < l.f(mid - 1000001);

    if (f2)
        swap(segTree[si], l);

    if (ss == se)
        return;
    else if (f1 != f2)
        update(2 * si, ss, mid, l);
    else
        update(2 * si + 1, mid + 1, se, l);
}

ll query(int si, int ss, int se, int x)
{
    ll res = segTree[si].f(x - 1000001);
    int mid = (ss + se) / 2;

    if (ss == se)
        return res;
    else if (x <= mid)
        return max(res, query(2 * si, ss, mid, x));
    else
        return max(res, query(2 * si + 1, mid + 1, se, x));
}

void update2(int si, int ss, int se, line l)
{
    int mid = (ss + se) / 2;
    bool f1 = segTree2[si].f(ss - 1000001) < l.f(ss - 1000001);
    bool f2 = segTree2[si].f(mid - 1000001) < l.f(mid - 1000001);

    if (f2)
        swap(segTree2[si], l);

    if (ss == se)
        return;
    else if (f1 != f2)
        update2(2 * si, ss, mid, l);
    else
        update2(2 * si + 1, mid + 1, se, l);
}

ll query2(int si, int ss, int se, int x)
{
    ll res = segTree2[si].f(x - 1000001);
    int mid = (ss + se) / 2;

    if (ss == se)
        return res;
    else if (x <= mid)
        return max(res, query2(2 * si, ss, mid, x));
    else
        return max(res, query2(2 * si + 1, mid + 1, se, x));
}

void solve()
{
    cin >> n;

    ll ans = 0;

    REP(i, 1, n)
    {
        cin >> arr[i];
        ans += arr[i] * i;
        arr[i] += arr[i - 1];
    }

    ll res = ans;

    // update(1, 1, 2000001, line(1, 0));
    // update(1, 1, 2000001, line(2, 0));
    // update(1, 1, 2000001, line(3, 0));
    // update(1, 1, 2000001, line(4, 0));
    // cout << max(-4LL, query(1, 1, 2000001, 1000000) + ans + arr[4] - (arr[4] - arr[3]) * 4);

    REP(i, 2, n)
    {
        update(1, 1, 2000001, line(i - 1, -arr[i - 2]));
        res = max(res, query(1, 1, 2000001, arr[i] - arr[i - 1] + 1000001) + ans + arr[i - 1] - (arr[i] - arr[i - 1]) * i);
    }

    RREP(i, n - 1, 1)
    {
        update2(1, 1, 2000001, line(i + 1, -arr[i + 1]));
        res = max(res, query2(1, 1, 2000001, (arr[i] - arr[i - 1]) + 1000001) + ans + arr[i] - (arr[i] - arr[i - 1]) * i);
    }

    cout << res;
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