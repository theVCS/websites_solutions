#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pdd pair<double, double>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define INF 0x3f3f3f3f
#define endl "\n"
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};
// while (T < q[i].t)
//     do_update(++T);
// while (T > q[i].t)
//     undo(T--);
// while (R < q[i].r)
//     add(++R);
// while (L > q[i].l)
//     add(--L);
// while (R > q[i].r)
//     remove(R--);
// while (L < q[i].l)
//     remove(L++);

vector<pdd> arr;

double dist(double x1, double y1, double x2, double y2, double xo, double yo)
{
    double A = (y1 - y2);
    double B = (x2 - x1);
    double C = -A * x1 - B * y1;
    return abs((A * xo + B * yo + C) / sqrt(A * A + B * B));
}

void solve()
{
    int n;
    double a, b;

    cin >> n;

    REP(i, 0, n)
    {
        cin >> a >> b;
        arr.push_back({a, b});
    }

    double ans = 10000000000;

    REP(i, 0, n)
    {
        double temp = 0;

        REP(j, 0, n)
        {
            temp = max(temp, dist(arr[i].first, arr[i].second, arr[(i + 1) % n].first, arr[(i + 1) % n].second, arr[j].first, arr[j].second));
        }

        ans = min(ans, temp);
    }

    cout << setprecision(15) << ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream fi("input.txt");
    // ofstream fo("output.txt");

    // fi >> input;
    // fo << output;

    int t = 1;

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //fi.close();
    //fo.close();

    return 0;
}