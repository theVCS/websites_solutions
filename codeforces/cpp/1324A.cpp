#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t, n, dum, var;
    bool istrue;
    cin >> t;

    while (t--)
    {
        istrue = true;
        cin >> n;
        n--;
        cin >> dum;
        var = dum % 2;

        while (n--)
        {
            cin >> dum;

            if (istrue)
            {
                if (var != dum % 2)
                {
                    istrue = false;
                }
            }
        }
        if (istrue)
        {
            cout << "YES"<<endl;
        }
        else
        {
            cout << "NO"<<endl;
        }
    }

    return 0;
}