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

#define maxN 501
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

int n, q;
char arr[maxN][maxN];
ll ft[maxN][maxN][26];

void update2(int index, ll val, int y, int alp)
{
    while (index <= n)
    {
        ft[y][index][alp] += val;
        index += (index & -1 * index);
    }
}

void update(int index, ll val, int x, int alp)
{
    while (index <= n)
    {
        update2(x, val, index, alp);
        index += (index & -1 * index);
    }
}

ll query2(int index, int y, int alp)
{
    ll sum = 0;

    while (index)
    {
        sum += ft[y][index][alp];
        index -= (index & -1 * index);
    }

    return sum;
}

ll query(int index, int x, int alp)
{
    ll sum = 0;

    while (index)
    {
        sum += query2(x, index, alp);
        index -= (index & -1 * index);
    }

    return sum;
}

ll acQuery(int x1, int y1, int x2, int y2)
{
    ll ans = 0;

    REP(i, 0, 25)
    {
        ans += (i + 1) * (query(y2, x2, i) - query(y1 - 1, x2, i) - query(y2, x1 - 1, i) + query(y1 - 1, x1 - 1, i));
    }

    return ans;
}

void solve()
{
    cin >> n >> q;

    REP(i,1,n)
    REP(j,1,n)
    REP(alp,0,25)
    ft[i][j][alp]=0;

    REP(i, 1, n)
    REP(j, 1, n)
    {
        cin >> arr[i][j];
        update(j, 1, i, arr[i][j] - 'A');
    }
    
    while (q--)
    {
        int code;
        cin >> code;

        if (code == 0)
        {
            int x, y;
            string str;
            cin >> x >> y >> str;
            y++;

            if (x == 0)
            {
                REP(i, 1, n)
                {
                    update(i, -1, y, arr[y][i] - 'A');
                    arr[y][i] = str[i - 1];
                    update(i, 1, y, arr[y][i] - 'A');
                }
            }
            else
            {
                REP(i, 1, n)
                {
                    update(y, -1, i, arr[i][y] - 'A');
                    arr[i][y] = str[i - 1];
                    update(y, 1, i, arr[i][y] - 'A');
                }
            }
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1++, y1++, x2++, y2++;
            cout << acQuery(x1, y1, x2, y2) << endl;
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

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}