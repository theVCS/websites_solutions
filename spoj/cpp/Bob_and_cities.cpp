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

#define maxN 1001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
#define printpoint(p) cout << p.x << " " << p.y << " " << p.z
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {0, 0, -1, 1, 1, -1, 1, -1};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};

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

int n, m, q;
char arr[maxN][maxN];
ll cost[maxN][maxN];
int sx, sy;
ll c[4];
vector<ll>calCost;

bool isValid(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > m || arr[x][y] == '#')
        return false;
    return true;
}

void dik()
{
    priority_queue<pair<ll,pii>, vector<pair<ll,pii>>, greater<>>pq;
    cost[sx][sy] = 0;
    pq.push({0, {sx,sy}});

    while (!pq.empty())
    {
        pair<ll,pii>node = pq.top();
        pq.pop();

        int x = node.second.first;
        int y = node.second.second;

        REP(i,0,3)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if(isValid(X,Y) && cost[X][Y] > node.first + c[i])
            {
                cost[X][Y] = node.first + c[i];
                pq.push({cost[X][Y], {X,Y}});
            }
        }
    }

    REP(i,1,n)
    {
        REP(j,1,m)
        {
            if(arr[i][j] == '.')
            calCost.push_back(cost[i][j]);
        }
    }

    sort(all(calCost));
}

int bs(ll reqCost)
{
    int start = 0, end = calCost.size()-1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if(calCost[mid] <= reqCost && (mid == end || calCost[mid+1] > reqCost))
            return mid;
        else if (calCost[mid] <= reqCost)
            start = mid+1;
        else 
            end = mid - 1;
    }
    
    return -1;
}

void solve()
{
    cin >> n >> m;

    REP(i,1,n)
    {
        REP(j,1,m)
        {
            cin >> arr[i][j];
            cost[i][j] = 1e18 + 100;
        }
    }

    cin >> c[0] >> c[1] >> c[2] >> c[3];
    cin >> sx >> sy;

    dik();

    ll ct;
    int q;
    cin >> q;

    while (q--)
    {
        cin >> ct;
        cout<<bs(ct)+1<<endl;
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