#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
vector<int> divisors[maxN];
int sieve[maxN];

void divInit()
{
    int div1, div2, i, j;
    for (i = 2; i < maxN; i++)
    {
        for (j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                div1 = j;
                div2 = i / j;

                divisors[i].push_back(div1);

                if (div1 != div2)
                {
                    divisors[i].push_back(div2);
                }
            }
        }
    }
}

void sieveinit()
{
    int i, j;

    sieve[1] = 1;

    for (i = 2; i < maxN; i++)
    {

        if (sieve[i] == 0)
        {
            sieve[i] = i - 1;

            for (j = i + i; j < maxN; j += i)
            {
                if (sieve[j] == 0)
                {
                    sieve[j] = j;
                }

                sieve[j] /= i;
                sieve[j] *= i - 1;
            }
        }
    }
}

ll sumpro(int n)
{
    ll sum = 0;
    int i;

    for (i = 2; i <= n; i++)
    {
        for (int P : divisors[i])
        {
            sum = (sum + (P * sieve[i / P]));
        }
        sum -= i;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    divInit();
    sieveinit();

    int n;

    while (1)
    {
        scanf("%d", &n);

        if (!n)
        {
            break;
        }

        cout << sumpro(n) << endl;
    }

    return 0;
}