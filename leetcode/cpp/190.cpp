#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        unsigned rev = 0;
        int j = 31;

        for (int i = 0; i < 32; i++)
        {
            if (n & (1 << i))
            {
                rev += 1 << j;
            }
            j--;
        }
        return rev;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}