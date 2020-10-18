#include <bits/stdc++.h>
#include <string>
using namespace std;

class myStack
{
    char stack[400];
    int top;

public:
    myStack()
    {
        top = -1;
    }

    void push(char c);
    char pop();
    myStack reverse(myStack operStack);
};

void myStack::push(char c)
{
    stack[++top] = c;
}

char myStack::pop()
{
    if (top == -1)
    {
        return false;
    }
    return stack[top--];
}

myStack myStack::reverse(myStack operStack)
{
    char temp;
    myStack dummy;

    while (temp = operStack.pop())
    {
        dummy.push(temp);
    }
    return dummy;
}

int main(int argc, char const *argv[])
{
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

    int t;
    string exp, answer;
    char temp, temp2;
    myStack varStack, operStack;

    cin >> t;

    while (t--)
    {
        answer = "";
        cin >> exp;

        for (int i = 0; i < exp.length(); i++)
        {
            temp = exp.at(i);
            if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '^')
            {
                operStack.push(temp);
            }
            else
            {
                varStack.push(temp);
            }

            operStack = operStack.reverse(operStack);

            while (temp = varStack.pop())
            {
                if (temp == ')')
                {
                    answer += operStack.pop();
                }
                else
                {
                    if (temp != '(')
                    {
                        answer += temp;
                    }
                }
            }
        }
        cout << answer << endl;
    }

    return 0;
}