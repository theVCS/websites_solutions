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

string s1, s2, s3;
vector<pii> sameVal[4][4];

string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++)
    {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
        str.push_back(carry + '0');

    reverse(str.begin(), str.end());

    return str;
}

bool flag;

void fun(string n1, string n2, int sn1, int sn2)
{
    if (flag)
        return;

    if (sn1 == 0 && sn2 == 0)
    {
        string res = findSum(n1, n2);

        for (pii e : sameVal[1][3])
        {
            if (s1[e.first] != res[e.second])
            {
                break;
            }
        }

        for (pii e : sameVal[2][3])
        {
            if (s2[e.first] != res[e.second])
            {
                break;
            }
        }

        cout << n1 << endl;
        cout << n2 << endl;
        cout << res << endl;
    }
    else
    {
        bool v1[10], v2[10];

        REP(i,0,9)v1[i]=v2[i]=true;

        for(char c: s1)v1[c - '0'] = false;
        for(char c: s2)v2[c - '0'] = false;
    }
}

void solve()
{
    cin >> s1 >> s2 >> s3;

    // finding which indexedes are same
    REP(i, 0, s1.size() - 1)
    {
        // checking for 1 - 2
        REP(i1, 0, s2.size() - 1)
        {
            if (s1[i] == s2[i1])
            {
                sameVal[1][2].push_back({i, i1});
                break;
            }
        }

        // checking for 1 - 3
        REP(i1, 0, s3.size() - 1)
        {
            if (s1[i] == s3[i1])
            {
                sameVal[1][3].push_back({i, i1});
                break;
            }
        }
    }

    // checking for 2 3
    REP(i, 0, s2.size() - 1)
    {
        REP(j, 0, s3.size() - 1)
        {
            sameVal[2][3].push_back({i, j});
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

    //cin >> t;

    while (t--)
    {
        solve();
    }

    //filptr.close();
    //outpter.close();

    return 0;
}