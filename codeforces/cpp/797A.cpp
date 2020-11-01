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

    int n, k;
    vector<int> fact;
    cin >> n >> k;

    if (k == 1)
    {
        cout << n;
        return 0;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                if (k == 1)
                {
                    break;
                }

                n /= i;
                fact.push_back(i);
                k--;
            }
        }
    }

    if (k != 1 || n == 1)
    {
        cout << -1;
    }
    else
    {
        for (int P : fact)
        {
            cout << P << " ";
        }
        cout << n;
    }

    return 0;
}