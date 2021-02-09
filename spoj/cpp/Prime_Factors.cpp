#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 100001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

vector<int> arr[maxN];

void init()
{
    for (int i = 2; i < maxN; i++)
    {
        if (arr[i].size() == 0)
        {
            for (int j = i; j < maxN; j += i)
            {
                arr[j].push_back(i);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    init();

    REP(i, 2, maxN)
    {
        printf("%d: ", i);
        for (int fact : arr[i])
            printf("%d ", fact);
        printf("\n");
    }

    return 0;
}