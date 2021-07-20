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

#define maxN 500001
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

const int blk = 900;
int n;
int arr[maxN];
vector<int> f[560];

int bs(int bl, int ele)
{
    int start = 0, end = f[bl].size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (f[bl][mid] < ele && (mid == end || f[bl][mid + 1] >= ele))
            return (f[bl].size() - mid - 1);
        else if (f[bl][mid] >= ele)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return f[bl].size();
}

ll query(int l, int r, int c)
{
    int lblk = l / blk;
    int rblk = r / blk;

    ll res = 0;

    if (lblk == rblk)
    {
        REP(i, l, r)
        {
            res += (arr[i] >= c);
        }
    }
    else
    {
        REP(i, l, blk * (lblk + 1) - 1)
        {
            res += (arr[i] >= c);
        }

        REP(i, lblk + 1, rblk - 1)
        {
            res += bs(i, c);
        }

        REP(i, rblk * blk, r)
        {
            res += (arr[i] >= c);
        }
    }

    return res;
}

void update(int index, int c)
{
    int bl = index / blk;

    int start = 0, end = f[bl].size() - 1;
    int ele = arr[index];
    arr[index] = c;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (f[bl][mid] == ele)
        {
            f[bl][mid] = c;
            sort(all(f[bl]));
            return;
        }
        else if (f[bl][mid] > ele)
            end = mid - 1;
        else
            start = mid + 1;
    }
}

void solve()
{
    cin >> n;

    REP(i, 1, n)
    {
        cin >> arr[i];
        f[i / blk].push_back(arr[i]);
    }

    REP(i, 0, n / blk)
    sort(all(f[i]));

    int q, code, l, r, c;
    cin >> q;

    REP(i, 1, q)
    {
        cin >> code;

        if (code == 0)
        {
            cin >> l >> r >> c;
            cout << query(l, r, c) << endl;
        }
        else
        {
            cin >> l >> c;
            update(l, c);
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