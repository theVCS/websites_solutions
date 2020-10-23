#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

void findB(int n)
{   
    int dum;
    vector<int> arr;

    while (n--)
    {
        cin >> dum;
        arr.push_back(dum);
    }

    int a = arr[0];

    for (int P : arr)
    {
        a = (a * P) /__gcd(a, P);
        cout << a << " ";
        a = P;
    }
    cout << a << endl;
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
        cin >> n;
        findB(n);
    }

    return 0;
}