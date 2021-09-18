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
#define maxN 100001
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
ll arr[maxN];
vector<ll> power_3;
vector<ll> segTree[4 * maxN];
 
void build(int si, int ss, int se)
{
    if (ss == se)
    {
        segTree[si].push_back(arr[ss]);
    }
    else
    {
        int mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        merge(all(segTree[2 * si]), all(segTree[2 * si + 1]), back_inserter(segTree[si]));
    }
}
 
bool bs(vector<ll> &vec, ll ele)
{
    int start = 0, end = vec.size() - 1;
 
    while (start <= end)
    {
        int mid = (start + end) / 2;
 
        if (arr[mid] == ele)
            return true;
        else if (arr[mid] < ele)
            start = mid + 1;
        else
            end = mid - 1;
    }
 
    return false;
}
 
int query(int si, int ss, int se, int qs, int qe, ll ele)
{
    if (ss > qe || se < qs)
        return 0;
 
    if (qs <= ss && qe >= se)
    {
        return upper_bound(all(segTree[si]), ele) - lower_bound(all(segTree[si]), ele);
    }
 
    int mid = (ss + se) / 2;
    return query(2 * si, ss, mid, qs, qe, ele) + query(2 * si + 1, mid + 1, se, qs, qe, ele);
}
 
void solve()
{
    ll i = 3;
 
    while (i <= 2000000000)
    {
        power_3.push_back(i);
        i *= 3;
    }
 
    cin >> n;
 
    REP(i, 1, n)
    cin >> arr[i];
 
    build(1, 1, n);
  
    ll cnt = 0;
 
    REP(i, 1, n)
    {
        for (ll ele : power_3)
        {
            if (ele <= arr[i])
                continue;
 
            cnt += query(1, 1, n, i + 1, n, ele - arr[i]);
        }
    }
 
    cout << cnt;
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
