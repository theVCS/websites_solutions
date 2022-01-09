#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238

#define maxN 1000001
#define INF 1000000000
#define mod 1000000007
#define printd(x) cout << fixed << setprecision(10) << x
// int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
// int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
// int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
// int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

double b, c;

double f(double x)
{
    return (x * x + b * x + c) / sin(x);
}

void solve()
{
    cin >> b >> c;

    double e = 0.000001;
    double l = e, r = (pi / 2);

    while (r - l > e)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        double v1 = f(m1);
        double v2 = f(m2);

        if (v1 < v2)
            r = m2;
        else if (v1 > v2)
            l = m1;
        else
            l = m1, r = m2;
    }
    
    printd(f(l)) << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t = 1;

    cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    return 0;
}