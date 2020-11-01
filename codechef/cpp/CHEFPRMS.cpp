#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 201
int sieve[maxN];
bool sprime[maxN];

void init()
{
    int cnt, n, k;
    bool opt = true;
    for (int i = 2; i < maxN; i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i; j < maxN; j += i)
            {
                if (sieve[j] == 0)
                {
                    sieve[j] = j / i;
                }
            }
        }
    }

    for (int i = 6; i < maxN; i++)
    {
        cnt = 0;
        n = i;
        while (sieve[n])
        {
            k = (n / sieve[n]);
            cnt++;
            n = sieve[n];

            if (sieve[n] && k == (n / sieve[n]))
            {
                cnt = 0;
                break;
            }
        }

        if (cnt == 2)
        {
            sprime[i] = true;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t, n;
    bool opt;

    cin >> t;

    while (t--)
    {
        cin >> n;
        opt = true;

        for (int i = 6; i <= (n / 2); i++)
        {
            if (sprime[i] && sprime[n - i])
            {
                cout << "YES" << endl;
                opt = false;
                break;
            }
        }

        if (opt)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}