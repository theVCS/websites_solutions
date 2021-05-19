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
#define maxN 500011
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

int n, k;
int arr[maxN];
vector<int> noChange;
vector<int> vec;
map<int, int> mp;
int ft[maxN];

void update(int index, int val, int n)
{
    while (index <= n)
    {
        ft[index] = max(ft[index], val);
        index += (index & -1 * index);
    }
}

ll query(int index)
{
    int res = 0;

    while (index)
    {
        res = max(ft[index], res);
        index -= (index & -1 * index);
    }

    return res;
}

int fun(int l, int r)
{
    mp.clear();
    vec.clear();

    REP(i, l + 1, r - 1)
    {
        if (((arr[i] >= arr[l] + (i - l)) || l == 0) && ((arr[i] <= arr[r] - (r - i)) || r == n + 1))
        {
            vec.push_back(arr[i] - i);
            mp[arr[i] - i];
        }
    }

    int res = 0;
    int timer = 0;
    int n = vec.size();

    for (auto &e : mp)
    {
        e.second = ++timer;
    }

    REP(i, 0, n - 1)
    {
        vec[i] = mp[vec[i]];
        ft[i] = 0;
    }
    ft[n] = 0;

    REP(i, 0, n - 1)
    {
        int hres = 1 + query(vec[i]);
        update(vec[i], hres, n);
        res = max(res, hres);
    }

    return res;
}

void solve()
{
    int index;

    cin >> n >> k;

    REP(i, 1, n)
    {
        cin >> arr[i];
    }

    int pre = 0;
    bool flag = false;

    REP(i, 1, k)
    {
        cin >> index;

        int ele_req = (index - pre) - 1;
        int ele_pre = (arr[index] - arr[pre]) - 1;

        if (ele_pre < ele_req && pre)
        {
            flag = true;
        }

        noChange.push_back(index);
        pre = index;
    }

    if (flag)
    {
        cout << -1 << endl;
        return;
    }

    pre = 0;
    int cnt = 0;

    for (int index : noChange)
    {
        cnt += fun(pre, index);
        // cout << pre << " " << index << " -> " << fun(pre, index) << endl;
        pre = index;
    }

    if (pre != n)
    {
        cnt += fun(pre,n+1);
        // cout<<pre<<" "<<n<<" -> " << fun(pre,n+1)<<endl;
    }

    cout << n - cnt - k;
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