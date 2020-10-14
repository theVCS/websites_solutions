#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int T, A, B;
    cin >> T;

    while (T--)
    {
        cin >> A >> B;

        int remain;
        remain = A % B;
        cout << remain<<endl;
    }

    return 0;
}