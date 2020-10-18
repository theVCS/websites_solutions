#include<iostream>
using namespace std;

long long factorial(long long  n)
{
    if (n)
    {
        return n*factorial(n - 1);
    }
    else
    {
        return 1;
    }
    
}

int main(int argc, char const *argv[]){
    int t;
    long long  n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cout<<factorial(n)<<endl;
    }
    
    return 0;
}