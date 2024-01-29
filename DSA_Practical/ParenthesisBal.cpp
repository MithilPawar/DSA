#include <iostream>
using namespace std;

#define STACKSIZE 5

class stack
{
private:
	char arr[STACKSIZE];
	int stack_top;

public:
	stack();
	void push(char x);
	char pop();
	bool is_empty();
};

stack::stack()
{
	stack_top = -1;
}

void stack::push(char val)
{
	stack_top = stack_top + 1;
	arr[stack_top] = val;
}

char stack::pop()
{
	char val;
	val = arr[stack_top];
	--stack_top;
	return val;
}

bool stack::is_empty()
{
	return (stack_top == -1);
}

int main()
{
	stack mystack;
	char exp[] = {'<', '{', '[', '(', ')', '}', '>', '\0'};
	int isValid = 1;

	for (int i = 0; exp[i] != '\0'; i++)
	{
		char test = exp[i];

		if (test == '{' || test == '[' || test == '(' || test == '<')
		{
			mystack.push(test);
		}
		else if (test == '}' || test == ']' || test == ')' || test == '>')
		{
			if (mystack.is_empty())
			{
				isValid = 0;
				break;
			}
			else
			{
				char comp = mystack.pop();
				if ((test == '}' && comp != '{') || (test == ']' && comp != '[') ||
					(test == ')' && comp != '(') || (test == '>' && comp != '<'))
				{
					isValid = 0;
					break;
				}
			}
		}
	}

	cout << "The given expression is:";
	for (int i = 0; exp[i] != '\0'; i++)
	{
		cout << exp[i] << "  ";
	}

	if (isValid && mystack.is_empty())
	{
		cout << "\nIn above expression, Parentheses are balanced." << endl;
	}
	else
	{
		cout << "\nIn above expression, Parentheses are not balanced." << endl;
	}

	return 0;
}
