#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
ll arr[maxN];
vector<int> ans;

void init()
{
    for (int i = 2; i < maxN; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i; j < maxN; j += i)
            {
                if (arr[j] == 0)
                {
                    arr[j] = j / i;
                }
            }
        }
    }
}

// bool istru(int a)
// {
//     int cnt, total = 0;
//     for (int i = 2; i * i <= a; i++)
//     {
//         if (a % i == 0)
//         {
//             cnt = 0;
//             while (a % i == 0)
//             {
//                 a /= i;
//                 cnt++;

//                 if (cnt > 1)
//                 {
//                     return false;
//                 }
//             }

//             total++;

//             if (total > 2)
//             {
//                 return false;
//             }
//         }
//     }

//     if (a > 1)
//     {
//         total++;
//     }

//     if (total == 2)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

bool checker(int n)
{
    int curDiv = n / arr[n], totalPrimes = 1;
    n = arr[n];

    while (arr[n])
    {
        if (curDiv == (n / arr[n]))
        {
            return false;
        }
        else
        {
            totalPrimes++;

            if (totalPrimes > 3)
            {
                return false;
            }

            curDiv = (n / arr[n]);
        }
        n = arr[n];
    }

    if (totalPrimes == 2)
    {
        return true;
    }
}

void fun()
{
    int curDiv, noDiv, totalDiv;
    for (int i = 50; i < maxN; i++)
    {
        int n = i;
        curDiv = n / arr[n];
        totalDiv = 1;
        noDiv = 1;
        n = arr[n];

        while (arr[n])
        {
            if (curDiv == n / arr[n])
            {
                noDiv++;
            }
            else
            {
                totalDiv *= (noDiv + 1);
                noDiv = 1;
                curDiv = n / arr[n];
            }
            n = arr[n];
        }

        totalDiv *= (noDiv + 1);

        if (checker(totalDiv))
        {
            ans.push_back(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    fun();

    for (int i = 0; i < ans.size(); i += 9)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}