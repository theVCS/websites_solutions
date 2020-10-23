#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> sumD;

bool digitSum(int n)
{
    int sum = 0;

    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    if (sum == 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void init()
{
    int i = 19;
    while (sumD.size() < 10001)
    {
        if (digitSum(i))
        {
            sumD.push_back(i);
        }

        i++;
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
    cout<<sumD[n - 1];

    return 0;
}