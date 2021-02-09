#include <bits/stdc++.h>
#include <string>
using namespace std;

pair<string, string> p[100];

int main()
{

    int n;

    cin >> n;

    // getline(cin, p[0].first);

    for (int i = 0; i < n; i++)
    {
        getline(cin, p[i].first);
        getline(cin, p[i].second);
        // scanf(" %[^\n]s", p[i].second);
    }

    for (int i = 0; i < n; i++)
    {
        cout << p[i].first << " - > " << p[i].second << endl;
    }

    return 0;
}