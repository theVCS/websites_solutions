#include<iostream>
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;

cpp_int factorial(cpp_int n)
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
    cpp_int n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cout<<factorial(n)<<endl;
    }
    
    return 0;
}