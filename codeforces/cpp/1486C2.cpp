#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
//#define bint cpp_int
#define pii pair<int, int>
#define mod 1000000007
#define REP(i, a, b) for (int i = a; i < b; i++)
#define maxN 1000001
#define all(x) (x).begin(), (x).end()
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

int binSearch(int start, int end, int secLar)
{
    if (start == end)
        return start;

    if (end < secLar)
    {
        int mid = (start + end + 1) / 2;
        int response;
        cout << "? " << mid << " " << secLar << endl;
        cin >> response;

        if (response == secLar)
            start = mid;
        else
            end = mid - 1;
    }
    else
    {
        int mid = (start + end) / 2;
        int response;
        cout << "? " << secLar << " " << mid << endl;
        cin >> response;

        if (response == secLar)
            end = mid;
        else
            start = mid + 1;
    }

    return binSearch(start, end, secLar);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, secondLargest;

    cin >> n;

    cout << "? 1 " << n << endl;
    cin >> secondLargest;

    int largestLeft = 1;

    if (secondLargest == 1)
        largestLeft = 0;
    else
    {
        int response;
        cout << "? 1 " << secondLargest << endl;
        cin >> response;

        if (response != secondLargest)
            largestLeft = 0;
    }

    int largest;

    if (largestLeft)
    {
        largest = binSearch(1, secondLargest - 1, secondLargest);
    }
    else
    {
        largest = binSearch(secondLargest + 1, n, secondLargest);
    }

    cout << "! "<<largest;

    return 0;
}