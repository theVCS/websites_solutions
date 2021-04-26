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
#define maxN 200011
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
#define pi 3.141592653589793238
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

map<ll, ll> mp;
ll arr[maxN];
ll sum;

void solve()
{
    sum = 0, mp.clear();

    int n;
    cin >> n;

    REP(i, 1, n + 2)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        sum += arr[i] * 1LL;
    }

    REP(i, 1, n + 2)
    {
        ll ele = (sum - arr[i]);

        if (ele % 2)
            continue;

        ele /= 2;


        ll index = mp[ele];

        if (ele == arr[i] && index == 1)
            continue;

        if (index)
        {
            // need not to show ele and arr[i]

            bool flagEle = true;
            bool flagArr = true;

            REP(j, 1, n + 2)
            {
                if (flagArr && arr[j] == arr[i])
                {
                    flagArr = false;
                    continue;
                }
                else if (flagEle && arr[j] == ele)
                {
                    flagEle = false;
                    continue;
                }
                else
                {
                    cout << arr[j] << " ";
                }
            }

            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
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