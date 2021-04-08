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
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<string> yedi;
map<string, int> act;
vector<int> arr;
int ft[30001];

int query(int index)
{
    int sum = 0;

    while (index)
    {
        sum += ft[index];
        index -= (index & -1 * index);
    }

    return sum;
}

void update(int index)
{
    while (index < 30001)
    {
        ft[index]++;
        index += (index & -1 * index);
    }
}

void solve()
{
    yedi.clear();
    act.clear();
    arr.clear();

    int n;
    cin >> n;
    string s;

    REP(i, 1, n + 1)
    {
        cin >> s;
        yedi.push_back(s);
        ft[i] = 0;
    }

    REP(i, 1, n + 1)
    {
        cin >> s;
        act[s] = i;
    }

    for (string s : yedi)
    {
        arr.push_back(act[s]);
        // cout << act[s] << " ";
    }
    // cout << endl;

    // now counting no of inversions
    int res = 0;

    REP(i, 0, n)
    {
        res += query(n) - query(arr[i]);
        update(arr[i]);
    }

    cout << res << endl;
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