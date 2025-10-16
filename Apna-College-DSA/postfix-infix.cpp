#include <iostream>
#include <stack>

using namespace std;

int prec(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

string reverseSring(string exp)
{
    for (int i = 0, j = exp.size() - 1; i < j; i++, j--)
    {
        swap(exp[i], exp[j]);
    }
    return exp;
}

string infixToPrefix(string exp)
{
}

string infixToPostfix(string exp)
{
    stack<char> st;
    string res;
    for (char &i : exp)
    {
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'))
        {
            res += i;
        }
        else if (i == '(')
        {
            st.push(i);
        }
        else if (i == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) > prec(i))
            {
                res += st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

int postfixEvaluation(string exp)
{
    stack<int> st;
    for (char &i : exp)
    {
        if (i >= '0' && i <= '9') // an operand
        {
            st.push(i - '0');
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (i)
            {
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    // string abc = infixToPostfix("(3-3/2)*(5/4-2)");
    string abc = infixToPostfix("3+5*2");
    cout << abc << endl;
    cout << "Evaluation : " << postfixEvaluation(abc) << endl;
    cout << "Reversed :" << reverseSring("hello hassan");
    return 0;
}