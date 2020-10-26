#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

int sansaXor(vector<int> arr)
{
    int size = arr.size();

    if (size % 2 == 0)
    {
        return 0;
    }

    for (int i = 2; i < size; i+=2)
    {
        arr[i] = arr[i] ^ arr[i - 2];
    }

    return arr[size - 1];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, dum;
    cin >> t;

    while (t--)
    {
        vector<int> arr;
        cin >> n;

        while (n--)
        {
            cin >> dum;
            arr.push_back(dum);
        }

        cout<<sansaXor(arr)<<endl;
    }

    return 0;
}