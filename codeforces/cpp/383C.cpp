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
#define INF 1000000000
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

int n, q;
int FT[2 * maxN], intime[maxN], outime[maxN], timer;
int level[maxN];
vector<int> arr[maxN];

void euler(int node, int par = -1, int l = 0)
{
    intime[node] = ++timer;
    FT[timer] = node;
    level[node] = l;

    for (int child : arr[node])
    {
        if (child != par)
        {
            euler(child, node, l + 1);
        }
    }

    outime[node] = ++timer;
    FT[timer] = node;
}

int segTree[maxN * 8], lazy[8 * maxN];
int val[maxN];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = val[FT[ss]];
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        // segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
    }
}

int query(int si, int ss, int se, int qi)
{
    if (lazy[si])
    {
        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];
        else
            segTree[si] += ((level[FT[ss]] & 1) ? -1 : 1) * lazy[si];

        lazy[si] = 0;
    }

    if (ss == se)
    {
        return segTree[si];
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
        return query(2 * si, ss, mid, qi);
    else
        return query(2 * si + 1, mid + 1, se, qi);
}

void update(int si, int ss, int se, int qs, int qe, int val)
{
    if (lazy[si])
    {
        if (ss != se)
            lazy[2 * si] += lazy[si], lazy[2 * si + 1] += lazy[si];
        else
            segTree[si] += ((level[FT[ss]] & 1) ? -1 : 1) * lazy[si];

        lazy[si] = 0;
    }

    if (ss > qe || se < qs)
        return;

    if (qs <= ss && qe >= se)
    {
        if (ss != se)
            lazy[2 * si] += val, lazy[2 * si + 1] += val;
        else
            segTree[si] += ((level[FT[ss]] & 1) ? -1 : 1) * val;

        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe, val);
    update(2 * si + 1, mid + 1, se, qs, qe, val);

    // segTree[si] = segTree[2 * si] + segTree[2 * si + 1];
}

void solve()
{
    int a, b;

    cin >> n >> q;

    REP(i, 1, n)
    cin >> val[i];

    REP(i, 1, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    euler(1);
    build(1,1,timer);
    int code;

    REP(i, 1, q)
    {
        cin >> code;

        if (code == 1)
        {
            cin >> a >> b;
            if (level[a] & 1)
                b *= -1;
            update(1, 1, timer, intime[a], outime[a], b);
        }
        else
        {
            cin >> a;
            cout << query(1, 1, timer, intime[a]) << endl;
        }
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