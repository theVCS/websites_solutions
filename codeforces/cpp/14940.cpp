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
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

bool check(string s)
{
    int left = 0;

    for (char c : s)
    {
        if (c == '(')
            left++;
        else
        {
            if (left == 0)
                return false;
            left--;
        }
    }

    if (left == 0)
        return true;

    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        vector<char> arr;

        arr.push_back(')');
        arr.push_back('(');

        string s;
        bool flag = true;
        cin >> s;

        for (char a : arr)
        {
            if(flag == false)break;
            for (char b : arr)
            {
                if(flag == false)break;
                for (char c : arr)
                {
                    string dum = s;

                    for (char &ch : dum)
                    {
                        if (ch == 'A')
                            ch = a;
                        if (ch == 'B')
                            ch = b;
                        if (ch == 'C')
                            ch = c;
                    }

                    if (check(dum))
                    {
                        cout << "YES" << endl;
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag)
            cout << "NO" << endl;
    }

    return 0;
}