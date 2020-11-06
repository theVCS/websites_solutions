#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

ll steps[maxN];

void init()
{
    steps[0] = 0;
    steps[1] = 1;
    steps[2] = 2;
    steps[3] = 4;

    for (int i = 4; i < maxN; i++)
    {
        steps[i] = (steps[i - 1] + steps[i - 2] + steps[i - 3]) % mod;
    }
    
}

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    init();

    int t;
    ll n;

    cin >> t;
    
    while (t--)
    {
        cin >> n;

        cout << steps[n]<<endl;
    }
    

    return 0;
}