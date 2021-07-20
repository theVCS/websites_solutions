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

#define maxN 500011
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
int intime[maxN], outime[maxN], timer;
int fat[maxN];
vector<int> arr[maxN];

void euler(int node, int par = 0)
{
    fat[node] = par;
    intime[node] = ++timer;

    for (int child : arr[node])
    {
        if (child != par)
        {
            euler(child, node);
        }
    }

    outime[node] = timer;
}

int segTree[maxN * 4], lazy[4 * maxN];
bool flg;

void query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return;

    if (lazy[si])
    {
        if (lazy[si] == 1)
            segTree[si] = 1;
        else
            segTree[si] = 0;

        if (ss != se)
            lazy[2 * si] = lazy[si], lazy[2 * si + 1] = lazy[si];

        lazy[si] = 0;
    }

    if (qs <= ss && qe >= se)
    {
        if (segTree[si] == 0)
            flg = true;
        return;
    }

    int mid = (ss + se) / 2;
    query(2 * si, ss, mid, qs, qe);
    query(2 * si + 1, mid + 1, se, qs, qe);
}

void update(int si, int ss, int se, int qs, int qe, int val)
{
    if (ss > qe || se < qs)
        return;

    if (lazy[si])
    {
        if (lazy[si] == 1)
            segTree[si] = 1;
        else
            segTree[si] = 0;

        if (ss != se)
            lazy[2 * si] = lazy[si], lazy[2 * si + 1] = lazy[si];

        lazy[si] = 0;
    }

    if (qs <= ss && qe >= se)
    {
        if (val == 1)
            segTree[si] = 1;
        else
            segTree[si] = 0;

        if (ss != se)
            lazy[2 * si] = val, lazy[2 * si + 1] = val;

        if (segTree[si] == 0)
            flg = true;

        return;
    }

    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe, val);
    update(2 * si + 1, mid + 1, se, qs, qe, val);

    segTree[si] = (segTree[2 * si] & segTree[2 * si + 1]);
}

void solve()
{
    int a, b;

    cin >> n;

    REP(i, 1, n - 1)
    {
        cin >> a >> b;
        arr[a].push_back(b), arr[b].push_back(a);
    }

    euler(1);

    cin >> q;

    REP(i, 1, q)
    {
        cin >> a >> b;

        if (a == 1)
        {
            flg = false;
            update(1, 1, timer, intime[b], outime[b], 1);

            if (flg && fat[b])
                update(1, 1, timer, intime[fat[b]], intime[fat[b]], 2);
        }
        else if (a == 2)
        {
            update(1, 1, timer, intime[b], intime[b], 2);
        }
        else
        {
            flg = false;
            query(1, 1, timer, intime[b], outime[b]);

            if (flg)
                cout << 0 << endl;
            else
                cout << 1 << endl;
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