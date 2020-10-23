#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 424251
bool arr[maxN];
vector<int> pp;
vector<int> primes;

bool isPallin(int n)
{
    int revn = 0, a = n;

    while (a)
    {
        revn = revn * 10 + a % 10;
        a /= 10;
    }

    if (n == revn)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void init()
{
    arr[0] = arr[1] = true;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (!arr[i])
        {
            for (int j = i * i; j < maxN; j += i)
            {
                arr[j] = true;
            }
        }
    }

    for (int i = 2; i < maxN; i++)
    {
        if (!arr[i])
        {
            primes.push_back(i);

            if (isPallin(i))
            {
                pp.push_back(i);
            }
        }
    }
}

void productPro(int n)
{
    int prod = 1;

    while (n)
    {
        if (n % 10)
        {
            prod *= n % 10;
        }
        n /= 10;
    }
    cout<<primes[prod - 1]<<endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int t, n;

    cin>>t;

    while (t--)
    {
        cin>>n;
        cout<<pp[n - 1]<<" ";
        productPro(pp[n - 1]);
    }
    

    return 0;
}