#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define STACKSIZE 5
using namespace std;

class stack
{
private:
	int arr[STACKSIZE];
	int stack_top;

public:
	stack();
	void push(int x);
	int pop();
	void peek();
	bool is_empty();
	bool is_full();
	int size();
	void display();
};

stack ::stack()
{
	stack_top = -1;
}

void stack ::push(int val)
{
	stack_top = stack_top + 1;
	arr[stack_top] = val;
}

int stack ::pop()
{
	int val;
	val = arr[stack_top];
	--stack_top;
	return val;
}

bool stack ::is_empty()
{
	if (stack_top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void stack::peek()
{
	if (stack_top < 0)
	{
		cout << "Stack is Empty" << endl;
	}
	else
	{
		int x = arr[stack_top];
		cout << "Top most element is:" << x << endl;
	}
}

bool stack ::is_full()
{
	if (stack_top == STACKSIZE - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int stack ::size()
{
	return stack_top + 1;
}

void stack ::display()
{
	if (stack_top == -1)
	{
		cout << "No elements to display " << endl;
		return;
	}

	cout << "Elements in the stack are:";
	for (int i = 0; i <= stack_top; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	system("cls");
	stack mystack;
	int val;
	int choice;

	while (1)
	{
		cout << "1. push\n";
		cout << "2. pop\n";
		cout << "3. peek\n";
		cout << "4. Display\n";
		cout << "5. Quit\n";
		cout << "Enter your choice:";
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (mystack.is_full() == false)
			{
				cout << " Enter value to be pushed:";
				cin >> val;
				mystack.push(val);
			}
			else
			{
				cout << "\n stack is full, can not push\n"
					 << endl;
			}
			break;

		case 2:
			if (mystack.is_empty() == false)
			{
				val = mystack.pop();
				cout << "\n popped element is:" << val << endl;
			}
			else
			{
				cout << " stack is empty, cannot pop" << endl;
			}
			break;

		case 3:
			mystack.peek();
			break;

		case 4:
			mystack.display();
			break;

		case 5:
			exit(1);

		default:
			cout << "Wrong choice\n";
		}
	}
	getch();
	return 0;
}
