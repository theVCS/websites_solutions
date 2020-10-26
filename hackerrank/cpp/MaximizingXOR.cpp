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

    int l, r;
    cin>>l>>r;
    int maxor = 0, a = l, b;

    while (a <= r)
    {
        b = a + 1;
        while (b <= r)
        {
            maxor = max(a ^ b, maxor);
            b++;
        }

        a++;
    }
    cout<<maxor;

    return 0;
}