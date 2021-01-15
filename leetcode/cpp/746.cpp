#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

class Solution
{
public:
    int t[1001];
    int minCost(vector<int> cost, int n, int ind)
    {
        if (ind >= n)
        {
            return 0;
        }
        else if (t[ind] != -1)
        {
            return t[ind];
        }
        else
        {
            return t[ind] = cost[ind] + min(minCost(cost, n, ind + 1), minCost(cost, n, ind + 2));
        }
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        memset(t, -1, sizeof(t));
        return min(minCost(cost, cost.size(), 0), minCost(cost, cost.size(), 1));
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}