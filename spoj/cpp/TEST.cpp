#include<iostream>
using namespace std;
int main(int argc, char const *argv[]){
    int n;
    bool leave = false;
    while (true)
    {
        if (n == 42)
        {
            leave = true;
        }

        cin>>n;

        if(!leave)
        {
            cout<<n<<endl;
        }
        
    }
       
    return 0;
}