#include <bits/stdc++.h>
using namespace std;

int reverse_finder(int number)
{
    int rev_num = 0;
    while (number)
    {
        rev_num = 10 * rev_num + number % 10;
        number /= 10;
    }
    return rev_num;
}

int main(int argc, char const *argv[])
{
    int t, n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cout<<reverse_finder(n)<<endl;
    }
    
    return 0;
}