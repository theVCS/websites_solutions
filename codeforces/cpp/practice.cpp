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
vector<pii> moves;

void towerOfHanoi(int n, char src = 'a', char hel = 'b', char des = 'c')
{
    if (n == 1)
    {
        if ((src == 'b' || src == 'c') && (des == 'c' || des == 'b'))
        {
            cout << src << " " << hel << endl;
            cout << hel << " " << des << endl;
            // moves.push_back({src-'a', hel-'a'});
            // moves.push_back({hel-'a', des-'a'});
        }
        else
        {
            cout << src << " " << des << endl;
            // moves.push_back({src-'a', des-'a'});
        }

        return;
    }

    if ((src == 'b' || src == 'c') && (des == 'c' || des == 'b'))
    {
        towerOfHanoi(n, src, des, hel);
        towerOfHanoi(n, hel, src, des);
    }
    else
    {
        towerOfHanoi(n - 1, src, des, hel);
        cout << src << " " << des << endl;
        // moves.push_back({src-'a', des-'a'});
        towerOfHanoi(n - 1, hel, src, des);
    }
}

void solve()
{
    cin >> n;
    towerOfHanoi(n);

    // vector<int>tow[3];

    // RREP(i,n,1)tow[0].push_back(i);

    // for(pii p: moves)
    // {
    //     tow[p.second].push_back(tow[p.first].back());
    //     tow[p.first].pop_back();
    // }

    // for(int ele: tow[2])
    // {
    //     cout<<ele<<" ";
    // }
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