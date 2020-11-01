#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
int sieve[maxN];

void init()
{
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
}

void display(int n)
{
    int fac = 0;
    while (sieve[n])
    {
        if (fac != n / sieve[n])
        {
            fac = n / sieve[n];
            printf("%d ", fac);
        }
        n = sieve[n];
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t, n, cnt = 1;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        printf("Case %d: ", cnt);
        display(n);
        cnt++;
    }
    

    return 0;
}