#include<iostream>
using namespace std;
int main(int argc, char const *argv[]){
    int T, A, B;
    cin>>T;
    int arr[T];

    for (int i = 0; i < T; i++)
    {
        cin>>A>>B;
        arr[i] = A + B;
    }

    for (int i = 0; i < T; i++)
    {
        cout<<arr[i]<<endl;
    }
    

    return 0;
}