#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 201
#define endl "\n"
#define INF 1000000000
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

set<char> dp[maxN][maxN][maxN];

set<char> findColors(int red, int blue, int green)
{
    // base case when only one card is left
    // we can mix {red,blue}, {red,green}, {blue, green}
    // we can replace {red,red}, {blue, blue}, {green,green}

    if (red == 0 && blue == 0)
    {
        return {'G'};
    }

    if (red == 0 && green == 0)
    {
        return {'B'};
    }

    if (green == 0 && blue == 0)
    {
        return {'R'};
    }

    if (dp[red][blue][green].size())
        return dp[red][blue][green];

    set<char> cs;

    if (red && blue)
        cs = findColors(red - 1, blue - 1, green + 1);
    for (char c : cs)
        dp[red][blue][green].insert(c);

    if (red && green)
        cs = findColors(red - 1, blue + 1, green - 1);
    for (char c : cs)
        dp[red][blue][green].insert(c);

    if (blue && green)
        cs = findColors(red + 1, blue - 1, green - 1);
    for (char c : cs)
        dp[red][blue][green].insert(c);

    if (red > 1)
        cs = findColors(red - 1, blue, green);
    for (char c : cs)
        dp[red][blue][green].insert(c);

    if (blue > 1)
        cs = findColors(red, blue - 1, green);
    for (char c : cs)
        dp[red][blue][green].insert(c);

    if (green > 1)
        cs = findColors(red, blue, green - 1);
    for (char c : cs)
        dp[red][blue][green].insert(c);

    return dp[red][blue][green];
}

void solve()
{
    int n, blue = 0, red = 0, green = 0;
    string s;

    cin >> n;
    cin >> s;

    // cout<<s.size();

    for (char c : s)
    {
        if (c == 'R')
            red++;
        else if (c == 'B')
            blue++;
        else
            green++;
    }

    // set<char> res = findColors(red, blue, green);

    // for (char c : res)
    //     cout << c;

    // bool redFlag = false;
    // bool blueFlag = false;
    // bool greenFlag = false;

    // if(red > 1)
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