#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define maxN 1000001
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
#define printd(x) cout << fixed << setprecision(10) << x
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

int n;

struct point
{
    ll x, y, z;
    int index;
};
vector<point> arr;

bool cmp(point a, point b)
{
    return (a.x < b.x) || (a.x == b.x && a.y < b.y) || (a.x == b.x && a.y == b.y && a.z < b.z);
}

// binary search functions for x variable
int xlower(ll x)
{
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid].x >= x && (mid == start || arr[mid - 1].x < x))
            return mid;
        else if (arr[mid].x >= x)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int xbs(int start, int end, ll x)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid].x == x && (mid == start || arr[mid - 1].x < x))
            return mid;
        else if (arr[mid].x == x)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int xupper(ll x)
{
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid].x <= x && (mid == end || arr[mid + 1].x > x))
            return mid;
        else if (arr[mid].x <= x)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

// binary search functions for y variable
int ylower(int start, int end, ll y)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid].y >= y && (mid == start || arr[mid - 1].y < y))
            return mid;
        else if (arr[mid].y >= y)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int ybs(int start, int end, ll y)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid].y == y && (mid == start || arr[mid - 1].y < y))
            return mid;
        else if (arr[mid].y == y)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return -1;
}

int yupper(int start, int end, ll y)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid].y <= y && (mid == end || arr[mid + 1].y > y))
            return mid;
        else if (arr[mid].y <= y)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

bool zCounter(int start, int end, int mn)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid].z >= mn && (mid == start || arr[mid - 1].z < mn))
            return true;
        else if (arr[mid].z >= mn)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return false;
}

bool yFinder(int l, int r, ll ymx, ll ymn, ll zmn)
{
    int ly = ylower(l, r, ymn);
    if (ly == -1)
        return true;
    int uy = yupper(l, r, ymx);

    cout << "y -> " << ly << " " << uy << endl;

    while (ly <= uy)
    {
        int _r = uy;
        int _l = ybs(ly, uy, arr[uy].y);
        uy = _l - 1;

        // now _l to _r is the range of one type of number now we need to find all those z in _l-_r
        if (zCounter(_l, _r, zmn))
            return false;
    }

    return true;
}

bool boundingBoxCounter(int start, int end)
{
    point a = arr[start];
    point b = arr[end];

    ll xmx = max(a.x, b.x);
    ll xmn = min(a.x, b.x);

    ll ymx = max(a.y, b.y);
    ll ymn = min(a.y, b.y);

    ll zmx = max(a.z, b.z);
    ll zmn = min(a.z, b.z);

    // firstly we need to find all those point whose x satisfy xmn <= x <= xmx
    int lx = xlower(xmn);
    if (lx == -1)
        return true;
    int ux = xupper(xmx);

    // cout<<"x range -> " << lx << " " << ux <<endl;

    int cnt = 0;

    // now in range l to r we need to find those y, for this we need to move in ranges
    while (lx <= ux)
    {
        int _r = ux;
        int _l = xbs(lx, ux, arr[ux].x);
        ux = _l - 1;

        // now _l to _r is the range of one type of number now we need to find all those y in _l-_r

        cout << "x -> " <<_l << " " << _r << endl;

        if (start >= _l && start <= _r)
        {
            if ((yFinder(_l, start - 1, ymx, ymn, zmn) & yFinder(start + 1, _r, ymx, ymn, zmn)) == false)
            {
                return false;
            }
        }
        if (end >= _l && end <= _r)
        {
            if ((yFinder(_l, end - 1, ymx, ymn, zmn) & yFinder(end + 1, _r, ymx, ymn, zmn)) == false)
            {
                return false;
            }
        }
        else
        {
            if (yFinder(_l, _r, ymx, ymn, zmn) == false)
            {
                return false;
            }
        }
    }

    return true;
}

void solve()
{
    cin >> n;
    point p;

    REP(i, 1, n)
    {
        cin >> p.x >> p.y >> p.z;
        p.index = i;
        arr.push_back(p);
    }

    sort(all(arr), cmp);

    // REP(i, 0, arr.size() - 1)
    // {
    //     REP(j, i + 1, arr.size() - 1)
    //     {
    //         // we are trying to remove arr[i] & arr[j] element if there is no axis-aligned minimum bounding box
    //         if (boundingBoxCounter(arr[i], arr[j]))
    //         {
    //             cout << arr[i].index << " " << arr[j].index << endl;
    //             arr.erase(arr.begin() + i);
    //             arr.erase(arr.begin() + j - 1);
    //             i = -1;
    //             break;
    //         }
    //     }
    // }

    if (boundingBoxCounter(0, 4))
    {
        cout << "PRINCE";
    }
    else
    {
        cout << "MISHRA";
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