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

#define maxN 100001
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

int n, m;
int grundy[1 << 16];
int cake[maxN];

int mex(set<int> &s)
{
    int n = 0;

    for (int e : s)
    {
        if (e != n)
            return n;

        n++;
    }

    return n;
}

int checkOne(int n, int l1, int l2, int r1, int r2)
{
    REP(l, l1, l2)
    {
        REP(r, r1, r2)
        {
            int bit = (1 << (l * 4 + r));

            if ((n & bit))
            {
                n ^= bit;
            }
            else
            {
                return -1;
            }
        }
    }

    return n;
}

int getGrundyNo(int n = ((1 << 16) - 1))
{
    if (grundy[n] != -1)
        return grundy[n];

    set<int> s;

    REP(l1, 0, 3)
    {
        REP(l2, l1, 3)
        {
            REP(r1, 0, 3)
            {
                REP(r2, r1, 3)
                {
                    int res = checkOne(n, l1, l2, r1, r2);

                    if (res != -1)
                    {
                        s.insert(getGrundyNo(res));
                    }
                }
            }
        }
    }

    return grundy[n] = mex(s);
}

ll segTree[maxN * 4];

void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si] = grundy[cake[ss]];
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        segTree[si] = (segTree[2 * si] ^ segTree[2 * si + 1]);
    }
}

ll query(int si, int ss, int se, int qs, int qe)
{
    if (ss > qe || se < qs)
        return 0;

    if (qs <= ss && qe >= se)
    {
        return segTree[si];
    }

    int mid = (ss + se) / 2;
    return (query(2 * si, ss, mid, qs, qe) ^ query(2 * si + 1, mid + 1, se, qs, qe));
}

void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        segTree[si] = grundy[cake[ss]];
        return;
    }

    int mid = (ss + se) / 2;

    if (qi <= mid)
    {
        update(2 * si, ss, mid, qi);
    }
    else
    {
        update(2 * si + 1, mid + 1, se, qi);
    }

    segTree[si] = (segTree[2 * si] ^ segTree[2 * si + 1]);
}

void solve()
{
    cin >> n >> m;

    REP(cak, 1, n)
    {
        int res = 0;

        REP(i, 0, 3)
        {
            REP(j, 0, 3)
            {
                char c;
                cin >> c;
                int bit = c - '0';

                if (bit)
                {
                    res ^= (1 << (i * 4 + j));
                }
            }
        }

        cake[cak] = res;
    }

    build(1, 1, n);

    int type;

    REP(i, 1, m)
    {
        cin >> type;

        if (type == 1)
        {
            int l, r;
            cin >> l >> r;

            ll res = query(1, 1, n, l, r);

            if (res)
            {
                cout << "Pishty" << endl;
            }
            else
            {
                cout << "Lotsy" << endl;
            }
        }
        else
        {
            int index;
            cin >> index;

            int res = 0;

            REP(k, 0, 3)
            {
                REP(l, 0, 3)
                {
                    char c;
                    cin >> c;
                    // cout<<c;
                    int bit = c - '0';

                    if (bit)
                    {
                        res ^= (1 << (k * 4 + l));
                    }
                }
                // cout<<endl;
            }

            cake[index] = res;
            // cout<<res<<endl;
            update(1, 1, n, index);
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

    memset(grundy, -1, sizeof(grundy));

    grundy[0] = 0;
    REP(i, 0, 15)
    {
        grundy[(1 << i)] = 1;
    }

    getGrundyNo();

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    // filptr.close();
    // outpter.close();

    return 0;
}