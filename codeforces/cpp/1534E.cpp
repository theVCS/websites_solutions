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

int n, k;
vector<int> arr[maxN];
int dis[maxN];
int parent[maxN];

void graphBuilder()
{
    REP(i, 0, n)
    {
        dis[i] = INF;
        int sb = i;      // set bits
        int nsb = n - i; // not set bits

        REP(j, 0, k)
        {
            // getting all the valid configutaions
            int p = k - j, q = j;
            int number = i;

            if (p <= sb && q <= nsb)
            {
                number -= p;
                number += q;

                arr[i].push_back(number);
            }
        }
    }
}

void bfs()
{
    parent[0] = -1;
    dis[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int child : arr[node])
        {
            if (dis[child] > dis[node] + 1)
            {
                parent[child] = node;
                dis[child] = dis[node] + 1;
                q.push(child);
            }
        }
    }
}

pii counter(int start, int end)
{
    REP(j, 0, k)
    {
        int p = k - j, q = j;
        int number = start;

        if (p <= start && q <= (n - start))
        {
            number -= p;
            number += q;

            if(number == end)return {p,q};
        }
    }
}

void solve()
{
    cin >> n >> k;
    graphBuilder();
    bfs();

    if (dis[n] == INF)
    {
        cout << -1;
        return;
    }

    vector<int> used, notUsed, path;
    int node = n;

    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    reverse(all(path));
    ll ans = 0;

    REP(i, 1, n)
    notUsed.push_back(i);

    REP(i,1,path.size()-1)
    {
        int start = path[i - 1];;
        int end = path[i];

        pii cnt = counter(start,end);

        // we need to choose cnt.first from used and cnt.second from not used
        cout<<"? ";
        REP(i,0,cnt.first-1)
        {
            cout<<used.front()<<" ";
            notUsed.push_back(used.front());
            used.erase(used.begin());
        }
        REP(i,0,cnt.second-1)
        {
            cout<<notUsed.front()<<" ";
            used.push_back(notUsed.front());
            notUsed.erase(notUsed.begin());
        }
        cout<<endl;
        fflush(stdout);
        ll res;
        cin >> res;
        ans ^= res;
    }

    cout<<"! "<<ans;
    fflush(stdout); 
}

int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

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