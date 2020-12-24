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

    int n, dum;
    vector<ll> arr;
    bool flag = true;

    cin >> n;

    REP(i, 0, n)
    {
        cin >> dum;
        arr.push_back(dum);
    }

    sort(arr.begin(), arr.end());

    REP(i, 0, n - 2)
    {
        if (arr[i] + arr[i + 1] > arr[i + 2])
        {
            cout << "YES";
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << "NO";
    }
    

    return 0;
}