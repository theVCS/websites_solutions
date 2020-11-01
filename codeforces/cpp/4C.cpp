#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string nam;
    cin >> t;

    map<string, int> names;

    while (t--)
    {
        cin >> nam;

        if (names.find(nam) == names.end())
        {
            names[nam] = 0;
            cout<<"OK"<<endl;
        }
        else
        {
            names[nam]++;
            cout << nam << names[nam] << endl;
        }
    }

    return 0;
}