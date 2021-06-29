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

string s;
int dp[2001][2001];

struct pallindrome
{
    int l, r;
} arr[4000001];

int isPallindrome(int l, int r)
{
    if (l >= r)
    {
        return dp[l][r] = 1;
    }
    else if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    else if (s[l] == s[r])
    {
        return dp[l][r] = isPallindrome(l + 1, r - 1);
    }
    else
    {
        return dp[l][r] = 0;
    }
}

int bs(int index, int n)
{
    int ele = arr[index].r;
    int start = index, end = n;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid].l > ele && (mid == 1 || arr[mid - 1].l <= ele))
        {
            return mid;
        }
        else if (arr[mid].l <= ele)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

void solve()
{
    cin >> s;

    memset(dp, -1, sizeof(dp));

    int n = 0;
    REP(i, 0, s.size() - 1)
    {
        REP(j, i, s.size() - 1)
        {
            if (isPallindrome(i, j))
            {
                n++;
                arr[n].l = i;
                arr[n].r = j;
            }
        }
    }   

    ll res = 0;

    REP(i, 1, n)
    {
        int index = bs(i,n);

        if(index != -1)
        {
            res += 1LL * (n - index + 1);
        }
    }

    cout<<res;
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