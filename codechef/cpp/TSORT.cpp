#include <bits/stdc++.h> 
using namespace std;

int main(int argc, char const *argv[]){
    int t;
    cin>>t;
    int size = t;
    int arr[t];
    while (--size > -1)
    {
        cin>>arr[size];
    }
    
    sort(arr, arr+t);

    while (++size < t)
    {
        cout<<arr[size]<<endl;
    }
    
    return 0;
}