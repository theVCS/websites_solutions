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

map<int,int>mp;

void solve()
{
    mp.clear();

    int n, s, k, dum;

    cin >> n >> s >> k;

    REP(i,0,k)
    {
        cin >> dum;
        mp[dum] = true;
    }

    int left = s;
    int right = s;

    while (left && mp[left])
        left--;


    while (right <= n && mp[right])
        right++;

    if(left == 0)
    {
        cout << right - s << endl;
        return;
    }

    if (right == n + 1)
    {
        cout << s - left << endl;
        return;
    }
    
    cout << min(s - left, right - s) << endl;
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