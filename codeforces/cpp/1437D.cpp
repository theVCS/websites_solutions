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
#define maxN 200001
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
int arr[maxN];
vector<int> inc_seq;

void solve()
{
    inc_seq.clear();

    cin >> n;

    REP(i, 1, n)
    cin >> arr[i];

    arr[1] = INF;

    int dep = 0;
    int cnt = 1;

    REP(i, 2, n)
    {
        if (arr[i - 1] < arr[i])
        {
            cnt++;
        }
        else
        {
            inc_seq.push_back(cnt);
            cnt = 1;
        }

        if (i == n)
            inc_seq.push_back(cnt);
    }

    // for (int ele : inc_seq)
    //     cout << ele << " ";
    // cout << endl;

    cnt = 1;
    int i = 1;

    while(i < inc_seq.size())
    {
        int cnt2 = 0;
        bool flag = true;

        while(cnt-- && i < inc_seq.size())
        {
            cnt2+=inc_seq[i];
            i++;

            if(flag)
            {
                dep++;
                flag = false;
            }
        }

        cnt = cnt2;
        // i--;
    }

    cout << dep << endl;
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