#include <bits/stdc++.h>
using namespace std;

int sum_finder(int number)
{
    if ((number/10) == 0)
    {
        return number;
    }
    else
    {
        return sum_finder(number/10);
    }
    
}

int main(int argc, char const *argv[]){
    int t, n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cout<<n%10 + sum_finder(n)<<endl;
    }
    
    return 0;
}