#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Expression
{
public:
    string prefix, infix, postfix;

    bool isOperator(char ch)
    {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
    }

    bool isOperand(char ch)
    {
        return (isalpha(ch) || isdigit(ch));
    }

    int precedence(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        if (op == '^')
            return 3;
        return 0;
    }

    void reverseString(string &str)
    {
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
        {
            char temp = str[i];
            str[i] = str[n - i - 1];
            str[n - i - 1] = temp;
        }
    }

    void prefixToInfix()
    {
        stack<string> stk;
        for (int i = prefix.length() - 1; i >= 0; i--)
        {
            if (isOperand(prefix[i]))
                stk.push(string(1, prefix[i]));
            else if (isOperator(prefix[i]))
            {
                string op1 = stk.top();
                stk.pop();
                string op2 = stk.top();
                stk.pop();
                string expr = "(" + op1 + prefix[i] + op2 + ")";
                stk.push(expr);
            }
        }
        infix = stk.top();
        stk.pop();
        cout << "Prefix: " << prefix << endl
             << "Infix: " << infix << endl;
    }

    void infixToPostfix()
    {
        postfix = "";
        stack<char> stk;
        for (char ch : infix)
        {
            if (isOperand(ch))
                postfix += ch;
            else if (ch == '(')
                stk.push(ch);
            else if (ch == ')')
            {
                while (!stk.empty() && stk.top() != '(')
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else if (isOperator(ch))
            {
                while (!stk.empty() && precedence(stk.top()) >= precedence(ch))
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(ch);
            }
        }
        while (!stk.empty())
        {
            postfix += stk.top();
            stk.pop();
        }
        cout << "Infix: " << infix << endl
             << "Postfix: " << postfix << endl;
    }

    void infixToPrefix()
    {
        string temp = infix;
        reverseString(temp);
        for (char &ch : temp)
        {
            if (ch == '(')
                ch = ')';
            else if (ch == ')')
                ch = '(';
        }
        infix = temp;
        infixToPostfix();
        reverseString(postfix);
        prefix = postfix;
        cout << "Infix: " << infix << endl
             << "Prefix: " << prefix << endl;
    }

    void postfixToInfix()
    {
        stack<string> stk;
        for (char ch : postfix)
        {
            if (isOperand(ch))
                stk.push(string(1, ch));
            else if (isOperator(ch))
            {
                string op2 = stk.top();
                stk.pop();
                string op1 = stk.top();
                stk.pop();
                string expr = "(" + op1 + ch + op2 + ")";
                stk.push(expr);
            }
        }
        infix = stk.top();
        stk.pop();
        cout << "Postfix: " << postfix << endl
             << "Infix: " << infix << endl;
    }

    void postfixToPrefix()
    {
        stack<string> stk;
        for (char ch : postfix)
        {
            if (isOperand(ch))
                stk.push(string(1, ch));
            else if (isOperator(ch))
            {
                string op2 = stk.top();
                stk.pop();
                string op1 = stk.top();
                stk.pop();
                string expr = ch + op1 + op2;
                stk.push(expr);
            }
        }
        prefix = stk.top();
        stk.pop();
        cout << "Postfix: " << postfix << endl
             << "Prefix: " << prefix << endl;
    }

    void prefixToPostfix()
    {
        stack<string> stk;
        for (int i = prefix.length() - 1; i >= 0; i--)
        {
            if (isOperand(prefix[i]))
                stk.push(string(1, prefix[i]));
            else if (isOperator(prefix[i]))
            {
                string op1 = stk.top();
                stk.pop();
                string op2 = stk.top();
                stk.pop();
                string expr = op1 + op2 + prefix[i];
                stk.push(expr);
            }
        }
        postfix = stk.top();
        stk.pop();
        cout << "Prefix: " << prefix << endl
             << "Postfix: " << postfix << endl;
    }

    int evaluatePrefix()
    {
        stack<int> stk;
        for (int i = prefix.length() - 1; i >= 0; i--)
        {
            if (isdigit(prefix[i]))
                stk.push(prefix[i] - '0');
            else if (isOperator(prefix[i]))
            {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                stk.push(applyOperator(a, b, prefix[i]));
            }
        }
        return stk.top();
    }

    int evaluatePostfix()
    {
        stack<int> stk;
        for (char ch : postfix)
        {
            if (isdigit(ch))
                stk.push(ch - '0');
            else if (isOperator(ch))
            {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(applyOperator(a, b, ch));
            }
        }
        return stk.top();
    }

    int applyOperator(int a, int b, char op)
    {
        if (op == '+')
            return a + b;
        if (op == '-')
            return a - b;
        if (op == '*')
            return a * b;
        if (op == '/')
            return b == 0 ? 0 : a / b;
        if (op == '^')
        {
            int res = 1;
            for (int i = 0; i < b; i++)
                res *= a;
            return res;
        }
        return 0;
    }
};

int main()
{
    Expression exp;
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Prefix to Infix\n";
        cout << "2. Infix to Postfix\n";
        cout << "3. Infix to Prefix\n";
        cout << "4. Postfix to Infix\n";
        cout << "5. Postfix to Prefix\n";
        cout << "6. Prefix to Postfix\n";
        cout << "7. Evaluate Prefix\n";
        cout << "8. Evaluate Postfix\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter prefix expression: ";
            cin >> exp.prefix;
            exp.prefixToInfix();
            break;
        case 2:
            cout << "Enter infix expression: ";
            cin >> exp.infix;
            exp.infixToPostfix();
            break;
        case 3:
            cout << "Enter infix expression: ";
            cin >> exp.infix;
            exp.infixToPrefix();
            break;
        case 4:
            cout << "Enter postfix expression: ";
            cin >> exp.postfix;
            exp.postfixToInfix();
            break;
        case 5:
            cout << "Enter postfix expression: ";
            cin >> exp.postfix;
            exp.postfixToPrefix();
            break;
        case 6:
            cout << "Enter prefix expression: ";
            cin >> exp.prefix;
            exp.prefixToPostfix();
            break;
        case 7:
            cout << "Enter prefix expression: ";
            cin >> exp.prefix;
            cout << "Result: " << exp.evaluatePrefix() << endl;
            break;
        case 8:
            cout << "Enter postfix expression: ";
            cin >> exp.postfix;
            cout << "Result: " << exp.evaluatePostfix() << endl;
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again!" << endl;
        }
    } while (choice != 9);

    return 0;
}