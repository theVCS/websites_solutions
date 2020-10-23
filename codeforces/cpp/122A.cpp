#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> ln;

bool isLucky(int n)
{
    int last;
    while (n)
    {
        last = n % 10;
        if (last != 4 && last != 7)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

void init()
{
    int maxN = 1001;

    for (int i = 4; i < maxN; i++)
    {
        if (isLucky(i))
        {
            ln.push_back(i);
        }
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

    for (int P : ln)
    {
        if (n % P == 0)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}