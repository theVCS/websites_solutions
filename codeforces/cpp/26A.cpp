#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
int ap[3001];

void init()
{
    int maxN = 3001, count, n;

    for (int i = 6; i < maxN; i++)
    {
        count = 0;
        n = i;
        for (int j = 2; j * j <= n; j++)
        {
            if (n % j == 0)
            {
                count++;
                if (count > 2)
                {
                    break;
                }
                while (n % j == 0)
                {
                    n /= j;
                }
            }
        }

        if (n > 1)
        {
            count++;
        }

        if (count == 2)
        {
            ap[i] = 1;
        }
    }

    for (int i = 6; i < maxN; i++)
    {
        ap[i] += ap[i - 1];
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    init();

    int n;
    
    cin>>n;
    
    cout<<ap[n];

    return 0;
}