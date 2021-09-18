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

#define maxN 300001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
#define printpoint(p) cout << p.x << " " << p.y << " " << p.z
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % c;
        }
        y = (y * 2LL) % c;
        b /= 2;
    }
    return x % c;
}

ll binExp(ll a, ll power, ll m = mod)
{
    ll res = 1;

    while (power)
    {
        if (power & 1)
            res = mulmod(res, a, m);
        a = mulmod(a, a, m);
        power >>= 1;
    }
    return res;
}

ll segTree[4 * maxN];

// range query
ll query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
    {
        return segTree[si];
    }

    int mid = (ss + se) / 2;
    return (query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe));
}

// point update
void update1(int si, int ss, int se, int qi, ll val)
{
    if (ss == se)
    {
        segTree[si] = val;
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
    {
        update1(2 * si, ss, mid, qi, val);
    }
    else
    {
        update1(2 * si + 1, mid + 1, se, qi, val);
    }

    segTree[si] = (segTree[2 * si] + segTree[2 * si + 1]);
}

// point update
void update2(int si, int ss, int se, int qi, ll val)
{
    if (ss == se)
    {
        segTree[si] += val;
        if (segTree[si] < 0)
            segTree[si] = 0;
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
    {
        update2(2 * si, ss, mid, qi, val);
    }
    else
    {
        update2(2 * si + 1, mid + 1, se, qi, val);
    }

    segTree[si] = (segTree[2 * si] + segTree[2 * si + 1]);
}

int n, q;
queue<int> vec[maxN];

void solve()
{
    cin >> n >> q;
    queue<int> que;
    int sz = 0;

    int timer = 1;

    while (q--)
    {
        int code;
        cin >> code;

        if (code == 1)
        {
            int x;
            cin >> x;
            que.push(x);
            vec[x].push(timer++);
            update2(1, 1, n, x, 1);
        }
        else if (code == 2)
        {
            int x;
            cin >> x;
            update1(1, 1, n, x, 0);
            while (vec[x].size())
                vec[x].pop();
        }
        else
        {
            int t;
            cin >> t;

            if (sz < t)
            {
                int req = t - sz;

                while (req--)
                {
                    int x = que.front();
                    if (vec[x].size() && vec[x].front() <= t)
                        update2(1, 1, n, x, -1), vec[x].pop();
                    que.pop();
                }

                sz = t;
            }
        }

        cout << segTree[1] << endl;
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

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}