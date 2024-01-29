#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class myNode
{
	int data;
	myNode *next;
	static int node_count;

public:
	myNode();
	myNode(int dataValue);

	void insertLast(int dataValue);
	void insertFirst(int dataValue);
	void insertAt(int dataValue, int pos);

	void removeLast();
	void removeFirst();
	void removeAt(int pos);

	void display();
	void sort();
	void reverse();
};
int myNode::node_count = 0;
myNode *head;

myNode ::myNode()
{
	data = 0;
	next = NULL;
}
myNode ::myNode(int val)
{
	data = val;
	next = NULL;
	node_count++;
}

void myNode ::display()
{
	myNode *trav = head;
	if (trav == NULL)
	{
		cout << "\n Empty node" << endl;
	}
	else if (trav->next == NULL)
	{
		cout << "\nData:\t" << trav->data << endl;
	}
	else
	{
		cout << "\nData: ";
		while (trav != NULL)
		{
			cout << trav->data << " ";
			trav = trav->next;
		}
	}
	cout << "\nTotal elements in linked list are:" << node_count << endl;
}

void myNode ::insertFirst(int dataValue)
{
	myNode *temp = new myNode(dataValue);

	if (head != NULL)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		head = temp;
	}
}

void myNode ::insertLast(int dataValue)
{
	myNode *temp = new myNode(dataValue);
	myNode *trav = head;

	if (trav != NULL)
	{
		while (trav->next != NULL)
		{
			trav = trav->next;
		}
		trav->next = temp;
	}
	else
	{
		head = temp;
	}
}

void myNode ::insertAt(int dataValue, int pos)
{
	if (pos > node_count + 1)
	{
		cout << "\n Wrong Position \n";
	}
	else
	{
		myNode *trav = head;

		int k = 1;
		if (head == NULL)
		{
			myNode *temp = new myNode(dataValue);
			head = temp;
		}
		else if (pos == 1)
		{
			insertFirst(dataValue);
		}
		else if (pos == node_count + 1)
		{
			insertLast(dataValue);
		}
		else
		{
			myNode *temp = new myNode(dataValue);
			while (k < pos - 1)
			{
				trav = trav->next;
				k = k + 1;
			}
			temp->next = trav->next;
			trav->next = temp;
		}
	}
}

void myNode ::removeFirst()
{
	myNode *trav = head;
	myNode *temp = new myNode();

	if (node_count == 1)
	{
		delete trav;
		head = NULL;
		node_count--;
	}
	else if (node_count > 1)
	{
		temp = trav;
		head = trav->next;
		free(temp);
		node_count--;
	}
}

void myNode ::removeLast()
{
	myNode *trav = head;
	myNode *temp = new myNode();

	if (node_count == 0)
	{
		cout << "Empty list. cannot remove";
	}
	else if (node_count == 1)
	{
		delete trav;
		head = NULL;
		node_count--;
	}
	else if (node_count > 1)
	{
		while (trav->next->next != NULL)
		{
			trav = trav->next;
		}
		temp = trav->next;
		free(temp);
		trav->next = NULL;
		node_count--;
	}
}

void myNode ::removeAt(int pos)
{
	if (pos > node_count)
	{
		cout << "\nWrong position \n";
	}
	else
	{
		myNode *temp = new myNode();
		myNode *trav = head;
		int k = 1;

		if (head == NULL)
		{
			head = temp;
		}
		else if (pos == 1)
		{
			removeFirst();
		}
		else if (pos == node_count)
		{
			removeLast();
		}
		else
		{
			while (k < pos - 1)
			{
				trav = trav->next;
				k = k + 1;
			}
			temp = trav->next;
			trav->next = temp->next;
			free(temp);
			node_count--;
		}
	}
}

void myNode ::sort()
{
	myNode *sort_head = head;
	myNode *trav = new myNode();
	while (sort_head->next != NULL)
	{
		trav = sort_head->next;
		while (trav != NULL)
		{
			if (trav->data < sort_head->data)
			{
				int temp = trav->data;
				trav->data = sort_head->data;
				sort_head->data = temp;
			}
			trav = trav->next;
		}
		sort_head = sort_head->next;
	}
}

void myNode ::reverse()
{
	myNode *prev = NULL;
	myNode *current = head;
	myNode *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
}

int main()
{
	head = new myNode();

	head->insertLast(500);
	cout << "\nInsert Last:";
	head->display();
	head->insertLast(200);
	cout << "\nInsert Last:";
	head->display();
	head->insertLast(300);
	cout << "\nInsert Last:";
	head->display();
	head->insertLast(400);
	cout << "\nInsert Last:";
	head->display();

	head->insertFirst(700);
	cout << "\nInsert first:";
	head->display();

	head->removeFirst();
	cout << "\nRemove first:";
	head->display();

	head->insertAt(600, 1);
	cout << "\nInsert At:";
	head->display();
	head->insertAt(200, 3);
	cout << "\nInsert At:";
	head->display();

	head->removeFirst();
	cout << "\nRemove first:";
	head->display();

	head->removeLast();
	cout << "\nRemove last:";
	head->display();

	head->removeAt(4);
	cout << "\nRemove At:";
	head->display();

	head->sort();
	cout << "\nSorted list:";
	head->display();

	head->reverse();
	cout << "\nReverse list:";
	head->display();
}
