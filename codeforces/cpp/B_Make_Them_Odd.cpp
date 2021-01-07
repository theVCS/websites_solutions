#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 200001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool vis[maxN];
map<int, bool> check;
ll arr[maxN];

void init()
{
    ll i = 1;

    while (i <= 1000000000)
    {
        check[i] = true;
        i *= 2;
    }
}

ll maxCounter(ll a)
{
    ll cnt = 0;

    while (a % 2 == 0)
    {
        cnt++;
        a /= 2;
    }

    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;
        ll ele, count = 0, res = 0;

        REP(i, 0, n)
        {
            cin >> ele;

            if (ele % 2 == 0)
            {
                arr[count] = ele;
                count++;
            }
        }

        sort(arr, arr + count, greater<>());

        REP(i, 0, count)
        {
            if (vis[i])
            {
                vis[i] = false;
                continue;
            }

            ele = arr[i];

            REP(j, i + 1, count)
            {
                if (!vis[j] && arr[i] % arr[j] == 0 && check[arr[i] / arr[j]])
                {
                    vis[j] = true;
                }
            }
            res += maxCounter(ele);
            vis[i] = false;
        }
        cout << res << endl;
    }

    return 0;
}