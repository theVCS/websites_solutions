#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size(), i;

        for (i = 0; i < len - 1; i++)
        {
            if (bits[i] == 1)
            {
                i++;
            }
            
        }
        
        if (i == len - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};

int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    



    return 0;
}