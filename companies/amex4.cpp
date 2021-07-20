#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
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

#define maxN 1000001
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

int n, m;
int iter;
map<string, map<string, int>> mp1;
map<string, int> mp2;
map<string, int> mp3;

struct Bdata
{
    string fn, ln;
    ll as, ta, tl, ho, bs, cl;
};
vector<Bdata> vec;

ll val(string s)
{
    ll ans = 0;
    ll p = 1;

    reverse(all(s));

    for (char c : s)
    {
        if(c == '-'){
            ans *= -1;
            return ans;
        }
        ans += (c - '0') * p;
        p *= 10;
    }

    return ans;
}

ll avg;

void add(string &s)
{
    int index = 0;
    Bdata b;

    string str;

    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }
        str.push_back(s[index++]);
    }
    b.fn = str;
    str.clear();

    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }
        str.push_back(s[index++]);
    }
    b.ln = str;
    str.clear();

    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }
        str.push_back(s[index++]);
    }
    b.as = val(str);
    str.clear();

    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }
        str.push_back(s[index++]);
    }
    b.ta = val(str);
    str.clear();

    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }
        str.push_back(s[index++]);
    }
    b.tl = val(str);
    str.clear();

    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }
        str.push_back(s[index++]);
    }
    b.ho = val(str);
    str.clear();

    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }
        str.push_back(s[index++]);
    }
    b.bs = val(str);
    str.clear();

    while (index < s.size())
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }
        str.push_back(s[index++]);
    }
    b.cl = val(str);
    str.clear();

    mp1[b.fn][b.ln] = ++iter;
    mp2[b.fn] = iter;
    mp2[b.ln] = iter;
    vec.push_back(b);

    avg += b.as;
}

struct app
{
    string id, fn, ln;
    ll inco;
    bool flag;
};
vector<app> apps;

void addApp(string &s)
{
    int index = 0;
    app a;

    string str;

    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }
        str.push_back(s[index++]);
    }
    a.id = str;
    str.clear();

    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }
        str.push_back(s[index++]);
    }
    a.fn = str;
    str.clear();

    while (true)
    {
        if (s[index] == ',')
        {
            index++;
            break;
        }
        str.push_back(s[index++]);
    }
    a.ln = str;
    str.clear();

    while (index < s.size())
    {
        str.push_back(s[index++]);
    }
    a.inco = val(str);
    str.clear();
    apps.push_back(a);
}

bool cmp(app a, app b)
{
    return a.id < b.id;
}

void process()
{
    for (auto e : apps)
    {
        // cout<<e.id<<" "<<e.fn<<" "<<e.ln<<" "<<e.inco<<endl;
        int index = mp1[e.fn][e.ln];

        if (index == 0)
            index = mp2[e.fn];

        if (index == 0)
            index = mp3[e.ln];

        index--;
        e.flag = false;

        cout<<index<<endl;

        if(index < 0)
        {
            continue;
        }

        if(vec[index].ta > vec[index].tl && vec[index].bs > 50 && vec[index].as > 0.1 * e.inco && vec[index].as * n > avg)
        {
            e.flag = true;
        }

        if(vec[index].ta > vec[index].tl && vec[index].ho && vec[index].bs > 30 && vec[index].as > 0.1 * e.inco && vec[index].as * n > avg)
        {
            e.flag = true;
        }
    }

    sort(all(apps), cmp);
}

void solve()
{
    string s;
    cin >> n;

    REP(i, 1, n)
    {
        cin >> s;
        add(s);
    }

    // avg /= n;   
    // cout<<avg<<endl;
    cin >> m;

    // for(auto e: vec)
    // {
    //     // cout<<e.fn<<" "<<e.ln<<" "<<e.as<<" "<<e.bs<;
    // }

    REP(i, 1, m)
    {
        cin >> s;
        addApp(s);
    }

    process();

    for(auto e: apps)
    {
        cout<<e.id<<" ";

        if(e.flag)cout<<"No";
        else cout<<"Yes";
        cout<<endl;
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