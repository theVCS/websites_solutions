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
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

map<int, int> mp;

void solve()
{
    mp.clear();
    priority_queue<int, vector<int>> q;

    int n, dum;

    cin >> n;

    REP(i, 1, n + 1)
    {
        cin >> dum;
        mp[dum]++;
    }

    for (auto e : mp)
        q.push(e.second);

    int s = n;

    while (q.size() >= 2)
    {
        int ele1 = q.top() - 1;
        q.pop();

        int ele2 = q.top() - 1;
        q.pop();

        s -= 2;

        if (ele1)
            q.push(ele1);
        if (ele2)
            q.push(ele2);
    }

    cout << s << endl;
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