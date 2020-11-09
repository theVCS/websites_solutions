#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

map<string, int> names;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int j = 0, n;
    string s1, s2;

    cin >> n;

    REP(i, 0, n)
    {
        cin >> s1 >> s2;

        if (names.find(s1) == names.end())
        {
            names[s1] = ++j;
        }

        cin >> s2;

        if (names.find(s2) == names.end())
        {
            names[s2] = ++j;
        }

        arr[names[s1]]
    }

    return 0;
}