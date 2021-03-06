#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, dum, maxV = 0, maxV_2 = 0;
    map<int, int> arr;

    cin >> n;

    REP(i, 0, n)
    {
        cin >> dum;
        arr[dum] += 1;
        maxV = max(dum, maxV);
    }

    for (int i = 1; i * i <= maxV; i++)
    {
        if (maxV % i == 0)
        {
            arr[i]--;

            if (i * i != maxV)
            {
                arr[maxV / i]--;
            }
        }
    }

    for(auto ele: arr)
    {
        if (ele.second)
        {
            maxV_2 = max(maxV_2, ele.first);
        }
    }

    cout << maxV << " " <<  maxV_2;

    return 0;
}