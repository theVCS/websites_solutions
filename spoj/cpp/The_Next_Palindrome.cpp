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
//int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
//int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
//int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i = n1 - 1; i >= 0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i] - '0') +
                   (str2[i + diff] - '0') +
                   carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining digits of str2[]
    for (int i = n2 - n1 - 1; i >= 0; i--)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry + '0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

string init(string a)
{
    bool flag = false;

    if (a == "0")
    {
        return "1";
    }
    if (a.size() == 1)
    {
        return "11";
    }
    

    string b = a.substr(0, ceil(a.size() / 2.0)), c;
    c = b;
    b = findSum(b, "1");

    if (c.size() < b.size())
    {
        flag = true;
    }

    if (a.size() % 2)
    {
        c = b.substr(0, b.size() - 1);
    }
    else
    {
        c = b;
    }
    reverse(c.begin(), c.end());

    if (flag)
    {
        return (b.substr(0, b.size() - 1) + c);
    }
    else
    {
        return (b + c);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string s;

    cin >> t;

    while (t--)
    {
        cin >> s;
        cout << init(s) << endl;
    }

    return 0;
}