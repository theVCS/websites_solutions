#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)

class Solution
{
public:
    int count(int n)
    {
        int cnt = 0;

        while (n)
        {
            cnt++;
            n = n & (n - 1);
        }
        
        return cnt;
    }

    vector<int> sortByBits(vector<int> &arr)
    {
        vector<int> arr0;
        vector<int> arr1;
        vector<int> arr2;
        vector<int> arr3;
        vector<int> arr4;

        for (int P : arr)
        {
            if (count(P) == 0)
            {
                arr0.push_back(P);
            }
            else if (count(P) == 1)
            {
                arr1.push_back(P);
            }
            else if (count(P) == 2)
            {
                arr2.push_back(P);
            }
            else if (count(P) == 3)
            {
                arr3.push_back(P);
            }
            else
            {
                arr4.push_back(P);
            }
        }

        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        sort(arr3.begin(), arr3.end());
        sort(arr4.begin(), arr4.end());

        vector<int> res;

        for (int P : arr0)
        {
            res.push_back(P);
        }
        for (int P : arr1)
        {
            res.push_back(P);
        }
        for (int P : arr2)
        {
            res.push_back(P);
        }
        for (int P : arr3)
        {
            res.push_back(P);
        }
        for (int P : arr4)
        {
            res.push_back(P);
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr{10,100,1000,10000};
    class Solution obj;
    vector<int>res;

    res = obj.sortByBits(arr);

    for(int P: res)
    {
        cout<<P<<" ";
    }

    return 0;
}