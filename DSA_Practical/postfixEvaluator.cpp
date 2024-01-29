#include <iostream>
#include <stack>
#include <cmath>
#include <cctype>

using namespace std;

class PostfixEvaluator
{
private:
    stack<double> operandStack;

    bool isOperator(char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
    }

    double applyOperator(char op, double operand1, double operand2)
    {
        switch (op)
        {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case '^':
            return pow(operand1, operand2);
        default:
            // Handle invalid operator
            throw invalid_argument("Invalid operator");
        }
    }

public:
    double evaluatePostfix(const string &expression)
    {
        for (char ch : expression)
        {
            if (isdigit(ch))
            {
                operandStack.push(ch - '0'); // Convert character to integer and push onto stack
            }
            else if (isOperator(ch))
            {
                if (operandStack.size() < 2)
                {
                    // Insufficient operands
                    throw invalid_argument("Insufficient operands for operator");
                }
                double operand2 = operandStack.top();
                operandStack.pop();
                double operand1 = operandStack.top();
                operandStack.pop();
                double result = applyOperator(ch, operand1, operand2);
                operandStack.push(result);
            }
            else
            {
                // Ignore spaces and invalid characters
                continue;
            }
        }

        if (operandStack.size() != 1)
        {
            // Invalid expression
            throw invalid_argument("Invalid postfix expression");
        }

        return operandStack.top();
    }
};

int main()
{
    string postfixExpression;
    cout << "Enter postfix expression: ";
    getline(cin, postfixExpression);

    PostfixEvaluator evaluator;

    try
    {
        double result = evaluator.evaluatePostfix(postfixExpression);
        cout << "Result: " << result << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
