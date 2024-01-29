#include <iostream>
#include <stdlib.h>
using namespace std;
class myNode
{
public:
    int data;
    myNode *next;
    static int node_count;
    myNode();
    myNode(int dataValue);
    void insertLast(int dataValue);
    void insertFirst(int dataValue);
    void insertAt(int dataValue, int pos);
    void removeFirst();
    void removeLast();
    void removeAt(int pos);
    void display();
    void reverse();
    void sort();
};
myNode *head;
int myNode::node_count = 0;
myNode::myNode()
{
    data = 0;
    next = NULL;
}
myNode::myNode(int val)
{
    data = val;
    next = NULL;
    node_count++;
}
void myNode::display()
{
    myNode *trav = head;
    if (trav == NULL)
    {
        cout << "\nEmpty List" << endl;
    }
    else
    {
        cout << "\nData: ";
        do
        {
            cout << trav->data << " ";
            trav = trav->next;
        } while (trav != head);
        cout << "\nTotal number of elements are " << node_count << endl;
    }
}
void myNode::insertFirst(int dataValue)
{
    myNode *temp = new myNode(dataValue);
    if (head != NULL)
    {
        temp->next = head;
        myNode *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = temp;
        head = temp;
    }
    else
    {
        head = temp;
        temp->next = head;
    }
    node_count++;
}
void myNode::insertLast(int dataValue)
{
    myNode *temp = new myNode(dataValue);
    if (head != NULL)
    {
        myNode *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = temp;
        temp->next = head;
    }
    else
    {
        head = temp;
        temp->next = head;
    }
    node_count++;
}
void myNode::insertAt(int dataValue, int pos)
{
    if (pos < 1 || pos > node_count + 1)
    {
        cout << "\nWrong Position" << endl;
    }
    else
    {
        if (pos == 1)
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
            myNode *trav = head;
            int k = 1;
            while (k < pos - 1)
            {
                trav = trav->next;
                k++;
            }
            temp->next = trav->next;
            trav->next = temp;
            node_count++;
        }
    }
}
void myNode::removeFirst()
{
    if (head == NULL)
    {
        cout << "Empty List. Cannot delete." << endl;
    }
    else
    {
        if (node_count == 1)
        {
            delete head;
            head = NULL;
        }
        else
        {
            myNode *temp = head;
            myNode *last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            head = head->next;
            last->next = head;
            delete temp;
        }
        node_count--;
    }
}
void myNode::removeLast()
{
    if (head == NULL)
    {
        cout << "Empty List. Cannot delete." << endl;
    }
    else
    {
        myNode *last = head;
        myNode *secondLast = NULL;
        while (last->next != head)
        {
            secondLast = last;
            last = last->next;
        }
        if (secondLast != NULL)
        {
            secondLast->next = head;
        }
        else
        {
            head = NULL;
        }
        delete last;
        node_count--;
    }
}
void myNode::removeAt(int pos)
{
    if (pos < 1 || pos > node_count)
    {
        cout << "Wrong Position" << endl;
    }
    else
    {
        if (pos == 1)
        {
            removeFirst();
        }
        else if (pos == node_count)
        {
            removeLast();
        }
        else
        {
            myNode *trav = head;
            int k = 1;
            while (k < pos - 1)
            {
                trav = trav->next;
                k++;
            }
            myNode *temp = trav->next;
            trav->next = temp->next;
            delete temp;
            node_count--;
        }
    }
}
void myNode::sort() {
    myNode *i, *j;
    int temp;
    for (i = head; i->next != head; i = i->next) {
        for (j = i->next; j != head; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void myNode::reverse()
{
    int i;
    for (i = node_count; i > 0; i--)
    {
        int val = head->data;
        removeFirst();
        insertAt(val, i);
    }
}
int main()
{
    myNode node;
    int choice, dataValue, pos;
    char ch;
    while (1)
    {
        cout << " 1.Insert First 2.Insert Last 3.Insert at Position" << endl;
        cout << " 4.Remove First 5.Remove Last 6.Remove at Position" << endl;
        cout << " 7.Display 8.Sort 9.Reverse" << endl;
        cout << " 10.Exit\n" << endl;
        cout << " Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << " Enter data value to insert at the beginning: ";
            cin >> dataValue;
            node.insertFirst(dataValue);
            break;
        case 2:
            cout << " Enter data value to insert at the end: ";
            cin >> dataValue;
            node.insertLast(dataValue);
            break;
        case 3:
            cout << " Enter data value to insert: ";
            cin >> dataValue;
            cout << " Enter position: ";
            cin >> pos;
            node.insertAt(dataValue, pos);
            break;
        case 4:
            node.removeFirst();
            break;
        case 5:
            node.removeLast();
            cout << endl;
            break;
        case 6:
            cout << " Enter position to remove: ";
            cin >> pos;
            node.removeAt(pos);
            break;
        case 7:
            node.display();
            break;
        case 8:
            node.sort();
            node.display();
            break;
        case 9:
            node.reverse();
            node.display();
            break;
        case 10:
            exit(0);
        default:
            cout << " Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}