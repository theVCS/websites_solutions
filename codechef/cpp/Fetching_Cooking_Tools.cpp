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

struct cook
{
    int cx, cy, tx, ty;

    pii ck()
    {
        return {cx, cy};
    }

    pii tl()
    {
        return {tx, ty};
    }
} arr[9];

int n;

int cost(pii x, pii y)
{
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int _util(int c1, int c2, int &c)
{
    int c1 = cost(arr[c].ck(), arr[c1].tl()) + cost(arr[c1].tl(), arr[c2].tl()) + cost(arr[c2].tl(), arr[c1].ck()) + cost(arr[c1].ck(), arr[c2].ck());
    int c1 = c2;

    
    int tc1 = cost(arr[c].ck(), arr[c1].tl()) + cost(arr[c1].tl(), arr[c2].tl()) + cost(arr[c2].tl(), arr[c1].ck()) + cost(arr[c1].ck(), arr[c2].ck());
    int c1 = c2;

    int tc1 = cost(arr[c].ck(), arr[c1].tl()) + cost(arr[c1].tl(), arr[c2].tl()) + cost(arr[c2].tl(), arr[c1].ck()) + cost(arr[c1].ck(), arr[c2].ck());
    int c1 = c2;

    int tc1 = cost(arr[c].ck(), arr[c1].tl()) + cost(arr[c1].tl(), arr[c2].tl()) + cost(arr[c2].tl(), arr[c1].ck()) + cost(arr[c1].ck(), arr[c2].ck());
    int c1 = c2;


}

int fun(int mask, int prev_cook = 8)
{
    vector<int> cooks_left;

    REP(i, 0, n - 1)
    {
        if ((mask & (1 << i)) == 0)
            cooks_left.push_back(i);
    }

    if (cooks_left.size() == 0)
    {
        return arr[prev_cook].cx + arr[prev_cook].cy;
    }
    else if (cooks_left.size() == 1)
    {
        int curr_cook = cooks_left[0];

        return cost(arr[prev_cook].ck(), arr[curr_cook].tl()) + cost(arr[curr_cook].tl(), arr[curr_cook].ck()) + fun(mask | (1 << curr_cook), curr_cook);
    }
    else
    {
        int res = INF;

        for (int i = 0; i < cooks_left.size(); i++)
        {
            int curr_cook = cooks_left[i];

            res = min(res, (abs(arr[prev_cook].cx - arr[curr_cook].tx) + abs(arr[prev_cook].cy - arr[curr_cook].ty)) + (abs(arr[curr_cook].cx - arr[curr_cook].tx) + abs(arr[curr_cook].cy - arr[curr_cook].ty)) + fun(mask | (1 << curr_cook), curr_cook));

            for (int j = i + 1; j < cooks_left.size(); j++)
            {
                int cook_1 = cooks_left[i], cook_2 = cooks_left[j];
            }
        }
    }
}

void solve()
{
    cin >> n;

    REP(i, 0, n - 1)
    cin >> arr[i].cx >> arr[i].cy >> arr[i].tx >> arr[i].ty;
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

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}