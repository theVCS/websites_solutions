#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define endl "\n"
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

map<ll, int> mp;
vector<ll> arr;

int findFirstMissing(int start, int end)
{
    if (start > end)
        return end + 1;

    if (start != arr[start])
        return start;

    int mid = (start + end) / 2;

    if (arr[mid] == mid)
        return findFirstMissing(mid + 1, end);

    return findFirstMissing(start, mid);
}

void solve()
{
    int n, k;
    ll dum;

    mp.clear();
    arr.clear();

    cin >> n >> k;

    REP(i, 0, n)
    {
        cin >> dum;
        mp[dum]++;
        arr.push_back(dum);
    }

    sort(all(arr));

    if (k)
    {
        ll ele = findFirstMissing(0, n - 1);
        ll newEle = ceil((ele + arr[n - 1]) / 2.0);

        if (newEle > arr[n - 1])
        {
            cout << mp.size() + k << endl;
            return;
        }

        mp[newEle]++;
        cout << mp.size() << endl;
    }
    else
    {
        cout << mp.size() << endl;
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

    cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}