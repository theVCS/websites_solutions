#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 3000
vector<int> mn;
int arr[maxN];

void init()
{
    for (int i = 2; i < maxN; i++)
    {
        if (!arr[i])
        {
            for (int j = i; j < maxN; j += i)
            {
                arr[j] += 1;
            }
        }
    }

    for (int i = 30; i < maxN; i++)
    {
        if (arr[i] > 2)
        {
            mn.push_back(i);
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

    cin>>t;

    while (t--)
    {
        cin>>n;
        cout<<mn[n - 1]<<endl;
    }
    

    return 0;
}