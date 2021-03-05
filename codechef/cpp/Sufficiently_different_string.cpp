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

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        int k;

        cin >> s >> k;

        map<char, bool> mp;

        for (int i = 0; i <= 25; i++)
            mp[char(i + 'a')] = false;

        for (char c : s)
            mp[c] = true;

        string t;

        for (auto e : mp)
        {
            if (k && e.second)
            {
                t.push_back(e.first);
                k--;
            }
        }

        if (k)
            cout << "NOPE" << endl;
        else
        {
            for (auto e : mp)
            {
                if (t.size() >= s.size())
                    break;
                if (e.second == false)
                    t.push_back(e.first);
            }
        }

        if (t.size() == s.size())
        {
            sort(all(t));
            cout << t << endl;
        }
        else
            cout << "NOPE" << endl;
    }

    return 0;
}