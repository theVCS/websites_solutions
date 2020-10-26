#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
vector<int> pall;

bool isPallin(int n)
{
    int rev = 0, a = n;

    while (a)
    {
        rev = 10 * rev + a % 10;
        a /= 10;
    }

    if (n == rev)
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
    int a = 100, b, db;

    while (a <= 999)
    {
        if (a % 11 == 0)
        {
            b = 999;
            db = 1;
        }
        else
        {
            b = 990;
            db = 11;
        }

        while (b >= a)
        {
            if (isPallin(a * b))
            {
                pall.push_back(a * b);
            }

            b -= db;
        }

        a++;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    sort(pall.begin(), pall.end());

    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;

        for(int i = pall.size() - 1; i > -1; i--)
        {
            if (pall[i] < n)
            {
                cout<<pall[i]<<endl;
                break;
            }
            
        }
    }

    return 0;
}