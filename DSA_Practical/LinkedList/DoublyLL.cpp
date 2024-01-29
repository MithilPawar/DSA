#include <iostream>
#include <stdlib.h>
using namespace std;
class myNode
{
public:
    int data;
    myNode *next;
    myNode *prev;
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
    prev = NULL;
}
myNode::myNode(int val)
{
    data = val;
    next = NULL;
    prev = NULL;
    node_count++;
}
void myNode::display()
{
    myNode *trav = head;
    if (trav == NULL)
    { // no nodes
        cout << "\n Empty MyNode" << endl;
    }
    else if (trav->next == NULL)
    {
        cout << "\n Data:\t" << trav->data << " ";
    }
    else
    {
        cout << "\n Data: ";
        while (trav != NULL)
        {
            cout << trav->data << " ";
            trav = trav->next;
        }
    }
    cout << "\n Total number of elements are " << node_count << endl;
}
void myNode::insertFirst(int dataValue)
{
    myNode *temp = new myNode(dataValue);
    if (head != NULL)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {
        head = temp;
    }
}
void myNode::insertLast(int dataValue)
{
    myNode *temp = new myNode(dataValue);
    myNode *trav = head;
    if (trav != NULL)
    {
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        temp->prev = trav;
        trav->next = temp;
    }
    else
    {
        head = temp;
    }
    node_count++;
}
void myNode::insertAt(int dataValue, int pos)
{
    if (pos > node_count + 1 || pos < 1)
    {
        cout << "\n Wrong Position" << endl;
    }
    else
    {
        myNode *temp = new myNode(dataValue);
        myNode *trav = head;
        int k = 1;
        if (head == NULL)
        {
            myNode *temp = new myNode(dataValue);
            head = temp;
            node_count++;
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
            node_count++;
        }
    }
}
void myNode::removeFirst()
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
        head->prev = NULL;
        node_count--;
    }
}
void myNode::removeLast()
{
    myNode *trav = head;
    if (node_count == 0)
    {
        cout << " Empty List. Cannot delete." << endl;
    }
    else if (node_count == 1)
    {
        delete trav;
        head = NULL;
        node_count--;
    }
    else
    {
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->prev->next = NULL;
        delete trav;
        node_count--;
    }
}
void myNode::removeAt(int pos)
{
    if (pos > node_count)
    {
        cout << " Wrong Position" << endl;
    }
    else
    {
        myNode *trav = head;
        myNode *temp = new myNode();
        int k = 1;
        if (node_count == 1)
        {
            delete trav;
            head = NULL;
            node_count--;
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
            temp->next->prev = trav;
            free(temp);
            node_count--;
        }
    }
}
void myNode::sort()
{
    myNode *sort_Head = head;
    myNode *trav = new myNode();
    while (sort_Head->next != NULL)
    {
        trav = sort_Head->next;
        while (trav != NULL)
        {
            if (trav->data < sort_Head->data)
            {
                int temp = trav->data;
                trav->data = sort_Head->data;
                sort_Head->data = temp;
            }
            trav = trav->next;
        }
        sort_Head = sort_Head->next;
    }
}
void myNode::reverse()
{
    myNode *temp = NULL;
    myNode *current = head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
    {
        head = temp->prev;
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
        cout << " 10.Exit" << endl;
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
            break;
        case 9:
            node.reverse();
            break;
        case 10:
            exit(0);
        default:
            cout << " Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}