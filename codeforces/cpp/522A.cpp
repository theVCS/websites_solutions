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

map<string, int> name;
map<string, vector<string>>arr;
map<string,bool>vis;

int dfs(string node)
{
    int dist = 0;

    vis[node] = true;

    for (string child : arr[node])
    {
        if (!vis[child])
        {
            dist = max(dfs(child), dist);
        }
    }

    return dist + 1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt = 1;
    string s1, s2;

    cin >> n;

    while (n--)
    {
        cin >> s1 >> s2;
        cin >> s2;

        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

        arr[s1].push_back(s2);
        arr[s2].push_back(s1);
    }

    cout << dfs("polycarp");

    return 0;
}