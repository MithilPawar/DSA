#include <iostream>
#include <climits>

using namespace std;

class stacklist
{
    int data;
    stacklist *next;
    static int node_count;
    const int max_size = INT_MAX;

public:
    stacklist();
    stacklist(int dataValue);

    void push(int dataValue);
    int pop();
    void display();
    int count();
    bool isEmpty();
    bool isFull();
};

stacklist *head = nullptr;
int stacklist::node_count = 0;

stacklist::stacklist()
{
    data = 0;
    next = nullptr;
}

stacklist::stacklist(int val)
{
    data = val;
    next = nullptr;
    node_count++;
}

void stacklist::display()
{
    stacklist *trav = head;

    if (trav == nullptr)
    {
        cout << "\nEmpty node" << endl;
    }
    else
    {
        cout << "\nData: ";
        while (trav != nullptr)
        {
            cout << trav->data << " ";
            trav = trav->next;
        }
    }
    cout << "\nTotal elements in linked list are: " << node_count << endl;
}

void stacklist::push(int dataValue)
{
    stacklist *temp = new stacklist(dataValue);
    stacklist *trav = head;

    if (trav != nullptr)
    {
        while (trav->next != nullptr)
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

int stacklist::pop()
{
    if (node_count == 0)
    {
        cout << "Empty list. Cannot remove.\n";
        return -1;
    }
    else if (node_count == 1)
    {
        int deletedData = head->data;
        delete head;
        head = nullptr;
        node_count--;
        return deletedData;
    }
    else
    {
        stacklist *trav = head;
        while (trav->next->next != nullptr)
        {
            trav = trav->next;
        }
        int deletedData = trav->next->data;
        delete trav->next;
        trav->next = nullptr;
        node_count--;
        return deletedData;
    }
}

int stacklist::count()
{
    return node_count;
}

bool stacklist::isEmpty()
{
    return node_count == 0;
}

bool stacklist::isFull()
{
    return false;
}

int main()
{
    head = new stacklist();

    head->push(500);
    cout << "\nPush:";
    head->display();
    head->push(200);
    cout << "\nPush:";
    head->display();
    head->push(300);
    cout << "\nPush:";
    head->display();
    head->push(400);
    cout << "\nPush:";
    head->display();

    cout << "\nCount: " << head->count() << endl;

    head->pop();
    cout << "\nPop:";
    head->display();

    cout << "\nCount: " << head->count() << endl;

    cout << "Is Empty: " << (head->isEmpty() ? "true" : "false") << endl;
    cout << "Is Full: " << (head->isFull() ? "true" : "false") << endl;

    return 0;
}
