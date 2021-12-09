#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define RREP(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define maxN 200001
#define INF 1000000000
#define mod 1000000007

int n, q;
int timer;
map<int, int> mp;
int arr[2 * maxN];
int rev[2 * maxN];

int lowerBound(int ele)
{
    int start = 1, end = timer;

    while (start<=end)
    {
        int mid = (start + end) / 2;

        if(rev[mid]<=ele && (mid==end||rev[mid+1]>ele))return mid;
        else if(rev[mid]<=ele)start=mid+1;
        else end=mid-1;
    }
    
    return -1;
}

int upperBound(int ele)
{
    int start = 1, end = timer;

    while (start<=end)
    {
        int mid = (start + end) / 2;

        if(rev[mid]>=ele && (mid==start||rev[mid-1]<ele))return mid;
        else if(rev[mid]>=ele)end=mid-1;
        else start=mid+1;
    }
    
    return -1;
}

struct query
{
    int code, a, b;
} Q[maxN];

ll ft[2 * maxN];

void update(int index, ll val)
{
    while (index <= timer)
    {
        ft[index] += val;
        index += (index & -1 * index);
    }
}

ll query(int index)
{
    ll sum = 0;

    while (index)
    {
        sum += ft[index];
        index -= (index & -1 * index);
    }

    return sum;
}

void solve()
{
    cin >> n >> q;

    REP(i, 1, n)
    {
        cin >> arr[i];
        mp[arr[i]];
    }

    REP(i, 1, q)
    {
        char code;
        cin >> code;
        cin >> Q[i].a >> Q[i].b;

        if (code == '!')
            Q[i].code = 1, mp[Q[i].b]; // update
        else
            Q[i].code = 2; // query
    }

    for (auto &e : mp)
        e.second = ++timer, rev[timer] = e.first;

    REP(i, 1, n)
    {
        arr[i] = mp[arr[i]];
        update(arr[i], 1);
    }

    REP(i, 1, q)
    {
        if (Q[i].code == 1)
        {
            update(arr[Q[i].a], -1);
            arr[Q[i].a] = mp[Q[i].b];
            update(arr[Q[i].a], 1);
        }
        else
        {
            int l = Q[i].a, r = Q[i].b;
            l = upperBound(l), r = lowerBound(r);
            cout << query(r) - query(l - 1) << endl;
        }
    }
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

    // cin >> t;

    REP(tc, 1, t)
    {
        // cout<<"Case "<<tc<<":"<<endl;
        solve();
    }

    // filptr.close();
    // outpter.close();

    return 0;
}
