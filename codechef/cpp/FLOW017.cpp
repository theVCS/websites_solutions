#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
    int t;
    cin>>t;
    int arr[3];
    while (t--)
    {
        cin>>arr[0]>>arr[1]>>arr[2];
        sort(arr, arr + 3);
        cout<<arr[1]<<endl;
    }
    
    return 0;
};