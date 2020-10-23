#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

void comDiv(int n)
{
    int div = 1, count;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count = 0;
            while (n % i == 0)
            {
                count++;
                n /= i;
            }
            div *= count + 1;
        }
    }

    if (n > 1)
    {
        div *= 2;
    }

    printf("%d\n", div);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a, b;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d%d", &a, &b);
        comDiv(__gcd(a, b));
    }

    return 0;
}