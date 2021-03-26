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

int arr[101];
int ch[101];
int cnt;

bool isValid(int index)
{
    // removing ones
    REP(i, 1, index)
    {
        if (ch[i] == 1 && arr[i] > 1)
        {
            return false;
        }
    }

    REP(i, index + 1, cnt + 1)
    {
        if (ch[i] == 0 && arr[i] > 1)
        {
            return false;
        }
    }

    return true;
}

void solve()
{
    string s;

    cin >> s;

    cnt = 1;

    arr[1] = 1;
    ch[1] = s[0] - '0';

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            arr[cnt]++;
        else
        {
            arr[++cnt] = 1;
            ch[cnt] = s[i] - '0';
        }
    }

    int left = 0;

    while (left <= s.size() + 1)
    {
        if (isValid(left))
        {
            cout << "YES" << endl;
            return;
        }
        left++;
    }

    cout << "NO" << endl;
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