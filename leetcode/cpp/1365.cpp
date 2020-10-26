#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> dum;
        int len = nums.size(), cnt;

        for (int i = 0; i < len; i++)
        {
            cnt = 0;
            for (int j = 0; j < len; j++)
            {
                if (j != i && nums[j] < nums[i])
                {
                    cnt++;
                }
            }
            dum.push_back(cnt);
        }
        return dum;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}