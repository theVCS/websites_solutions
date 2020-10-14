#include<iostream>
using namespace std;

long long reverse(long long n)
{
    long long rev_n = 0;
    while (n)
    {
        rev_n = 10*rev_n + n % 10;
        n /= 10;
    }
    return rev_n;
}

int main(int argc, char const *argv[]){
    int N;
    cin>>N;
    long long a, b;
    while (N--)
    {
        cin>>a>>b;
        a = reverse(a);
        b = reverse(b);
        cout<<reverse(a + b)<<endl;
    }
    
    return 0;
}