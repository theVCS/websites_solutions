#include<iostream>
using namespace std;

long long zero_calculator(long long integer)
{
    long long divider = 5, sum = 0, val;
    while (true)
    {
        val = integer/divider;
        if (val)
        {
            sum += val;
        }
        else
        {
            break;
        }
        divider *= 5;
    }
    return sum;
}

int main(int argc, char const *argv[]){
    int t;
    cin>>t;
    long long n;
    while (t--)
    {
        cin>>n;
        cout<<zero_calculator(n)<<endl;
    }
    
    return 0;
}