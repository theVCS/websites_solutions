/*
 * Outputs random number between 1 and 10^6, inclusive.
 * To generate different values, call "igen.exe" with different parameters.
 * For example, "igen.exe 1" returns 504077, but "igen.exe 3" returns 808747.
 * 
 * It is typical behaviour of testlib generator to setup randseed by command line.
 */

#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int n = 100;

    for (int i = 0; i < n; i++)
    {
        cout << "generator " << rnd.next(1, 10000) << " > $" << endl;
    }

    return 0;
}
