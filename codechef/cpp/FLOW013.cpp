#include <bits/stdc++.h>
using namespace std;

bool check_valid(int a, int b, int c)
{
    if (a + b + c == 180)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main(int argc, char const *argv[]){
    int t, a, b, c;
    cin>>t;
    while (t--)
    {
        cin>>a>>b>>c;
        if(check_valid(a, b, c))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}