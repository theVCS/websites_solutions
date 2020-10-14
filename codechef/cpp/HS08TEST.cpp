#include<iostream>
using namespace std;
int main(int argc, char const *argv[]){
    int x;
    float y;
    cin>>x;
    cin>>y;
    if (x % 5)
    {
        cout<<y;
    }
    else
    {
        cout<<(y - x - 0.5 >= 0 ? y - x - 0.5 : y);
    }
    
    return 0;
}