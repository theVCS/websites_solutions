#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

void andProduct(int a, int b)
{

    int sum = 0, d = b - a  + 1, f = 1;

    for (ll i = 0; i < 32; i++)
    {
        if (d <= (f << i))
        {
            if ((a & (f << i)) && (b & (f << i)))
            {
                sum += (f << i);
            }
        }
    }
    cout << sum << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a, b;

    cin >> t;

    while (t--)
    {
        cin >> a >> b;
        andProduct(a, b);
    }

    return 0;
}