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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

string s;

int build(char x, char y)
{
    int cnt = 0;

    for(char c: s)
    {
        if(c == x)
        {
            cnt++;
            swap(x,y);
        }
    }

    if(cnt & 1 && x != y)cnt--;

    return cnt;
}

void solve()
{
    cin >> s;

    int cnt[10] = {0};

    for (char c : s)
    {
        cnt[c - '0']++;
    }

    char ele;
    int sz = 0;

    REP(i, 0, 9)
    {
        if (cnt[i] == 0)
            continue;

        REP(j, 0, 9)
        {
            if (cnt[j] == 0)
                continue;
        
            sz = max(sz,build(char('0'+i),char('0'+j)));
        }
    }

    cout << s.size() - sz << endl;
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