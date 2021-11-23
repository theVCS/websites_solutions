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

#define maxN 1025
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
            res = mulmod(res,a,m);
        a = mulmod(a,a,m);
        power >>= 1;
    }
    return res;
}

int n;
ll arr[maxN][maxN];

template <class T>
class FenwickTree2D
{
    int n, m;
    vector<vector<T>> BIT;

public:
    FenwickTree2D(int N, int M)
    {
        n = N;
        m = M;
        BIT.resize(n + 1);

        for (vector<T> &vec : BIT)
            vec.assign(m + 1, 0);
    }

    T __query__(int x, int y)
    {
        T sum = 0;

        while (y > 0)
        {
            sum += BIT[x][y];
            y -= (y & -y);
        }

        return sum;
    }

    T _query_(int x, int y)
    {
        T sum = 0;

        while (x > 0)
        {
            sum += __query__(x, y);
            x -= (x & -x);
        }

        return sum;
    }

    T query(int x2, int y2, int x1, int y1)
    {
        return _query_(x2, y2) - _query_(x1 - 1, y2) - _query_(x2, y1 - 1) + _query_(x1 - 1, y1 - 1);
    }

    void __update__(int x, int y, T val)
    {
        while (y <= m)
        {
            BIT[x][y] += val;
            y += (y & -y);
        }
    }

    void update(int x, int y, T val)
    {
        while (x <= n)
        {
            __update__(x, y, val);
            x += (x & -x);
        }
    }
};

void solve()
{
    cin>>n;
    memset(arr,0,sizeof(arr));
    FenwickTree2D<ll>ft(n,n);

    while (true)
    {
        string s;
        cin>>s;

        if(s[1]=='E')
        {
            ll x,y,e;
            cin>>x>>y>>e;
            x++,y++;
            ft.update(x,y,e-arr[x][y]);
            arr[x][y]=e;
        }
        else if(s[1]=='U')
        {
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;     
            x1++,y1++,x2++,y2++;
            cout<<ft.query(x2,y2,x1,y1)<<endl;
        }
        else
        {
            return;
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

    REP(tc,1,t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}