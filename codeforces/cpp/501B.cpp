#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

map<string, string> arr;
map<string, bool>vis;
vector<string> s;

string find(string s)
{
    if (arr[s] == "")
    {
        return s;
    }
    return arr[s] = find(arr[s]);
}

void merge(string s1, string s2)
{
    arr[s1] = s2;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;
    string s1, s2;

    cin >> q;

    while (q--)
    {
        cin >> s1 >> s2;

        if (vis[s1] == false)
        {
            s.push_back(s1);
        }
        
        vis[s1] = vis[s2] = true;

        s1 = find(s1);
        s2 = find(s2);

        if (s1 != s2)
        {
            merge(s1, s2);
        }
    }

    cout << s.size() << endl;

    for (string e : s)
    {
        cout << e << " " << find(e) << endl;
    }

    return 0;
}