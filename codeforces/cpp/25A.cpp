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

    int n, k, ec = 0, oc = 0, ei, oi;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> k;

        if (k % 2)
        {
            oc++;
            oi = i + 1;
        }
        else
        {
            ec++;
            ei = i + 1;
        }
    }

    if (ec < oc)
    {
        cout << ei << endl;
    }
    else
    {
        cout << oi << endl;
    }

    return 0;
}