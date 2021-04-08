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

int n;
string s;
vector<string> res;
string a, b;

void fun(int index = 0, int ob1 = 0, int ob2 = 0)
{
    if (ob1 > n - index)
        return;
    if (ob2 > n - index)
        return;
    if (res.size() == 2)
        return;

    if (index == n)
    {
        // cout << a << " " << b << endl;
        if (ob1 == 0 && ob2 == 0)
        {
            res.push_back(a);
            res.push_back(b);
        }

        return;
    }
    else
    {
        if (s[index] == '1')
        {
            a = a + '(';
            b = b + '(';
            fun(index + 1, ob1 + 1, ob2 + 1);
            a.pop_back();
            b.pop_back();

            if (ob1 && ob2)
            {
                a = a + ')';
                b = b + ')';
                fun(index + 1, ob1 - 1, ob2 - 1);
                a.pop_back();
                b.pop_back();
            }
        }
        else
        {
            if (ob1 > 0)
            {
                a = a + ')';
                b = b + '(';
                fun(index + 1, ob1 - 1, ob2 + 1);
                a.pop_back();
                b.pop_back();
            }

            if (ob2 > 0)
            {
                a = a + '(';
                b = b + ')';
                fun(index + 1, ob1 + 1, ob2 - 1);
                a.pop_back();
                b.pop_back();
            }
        }
    }
}

void solve()
{
    cin >> n >> s;
    res.clear();

    if (s[0] == '0' || s[n - 1] == '0')
    {
        cout << "NO" << endl;
        return;
    }

    fun();

    if (res.size() < 2)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (string k : res)
    {
        cout << k << endl;
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