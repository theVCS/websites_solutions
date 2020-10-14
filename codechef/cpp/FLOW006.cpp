#include<iostream>
using namespace std;

int sum_digit(int number)
{
    if (number)
    {
        return number%10 + sum_digit(number/10);
    }
    else
    {
        return 0;
    }
    
}

int main(int argc, char const *argv[]){
    int T, n;
    cin>>T;
    int arr[T];

    for (int i = 0; i < T; i++)
    {
        cin>>n;
        arr[i] = sum_digit(n);    
    }
    
    for (int i = 0; i < T; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}