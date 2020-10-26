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

    vector<int> arr;
    int n, dum, dig = 0, cnt;
    cin >> n;

    while (n--)
    {
        cin >> dum;
        arr.push_back(dum);
    }

    for (int i = 0; i < 32; i++)
    {
        cnt = 0;
        for (int P : arr)
        {
            if (P & (1<<i))
            {
                cnt++;
            }
        }

        cnt %= 2;
        dig += cnt * (1<<i);
    }

    cout<<dig;

    return 0;
}