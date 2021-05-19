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

int n, m;
vector<int> friends[maxN];
int cnt[maxN];
int days[maxN];
int daySize[maxN];

bool cmp(int a, int b)
{
    return (daySize[a] >= daySize[b]);
}

void solve()
{
    cin >> n >> m;

    REP(i,1,n)friends[i].clear();

    int tot = 0;

    REP(i, 1, m)
    {
        int k, fri;

        cin >> k;
        daySize[i] = k;
        days[i] = 0;
        cnt[i] = 0;

        if (k == 1)
        {
            cin >> fri;
            cnt[fri]++;
            days[i] = fri;
            // daySize[i]--;
            tot++;
        }
        else
        {
            REP(j, 1, k)
            {
                cin >> fri;
                friends[fri].push_back(i);
            }
        }
    }

    int mxVal = (m + 1) / 2;

    REP(i, 1, n)
    {
        if (cnt[i] > mxVal)
        {
            cout << "NO";
            return;
        }

        sort(all(friends[i]), cmp);

        for (int day : friends[i])
        {
            if (cnt[i] == mxVal)
            {
                break;
            }

            if (days[day])
                continue;

            days[day] = i;
            // daySize[i]--;
            cnt[i]++;
            tot++;
        }
    }

    if (tot == m)
    {
        cout << "YES" << endl;

        REP(i, 1, m)
        cout << days[i] << " ";
        cout << endl;
        return;
    }

    cout << "NO" << endl;
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