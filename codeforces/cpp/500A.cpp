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

    int n, ex, index = 1;
    bool flag = true;

    cin >> n >> ex;

    int arr[n];

    REP(i, 1, n)
    {
        cin >> arr[i];
    }

    while (index <= n)
    {
        if (index == ex)
        {
            flag = false;
            break;
        }

        if (index == n)
        {
            break;
        }
        

        index = index + arr[index];
    }

    if (flag)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    

    return 0;
}