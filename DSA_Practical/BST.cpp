#include <iostream>
#include <stdlib.h>
using namespace std;
class myBST
{
public:
    int data;
    static int count;
    myBST *left;
    myBST *right;
    myBST(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        count++;
    }
    myBST()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    void insertNode(int);
    void removeNode(int);
    void inorder(myBST *);
    void preorder(myBST *);
    void postorder(myBST *);
    void smallest(myBST *);
    int largest(myBST *);
    void search(int);
};

myBST *root;
int myBST::count = 0;
void myBST::insertNode(int val)
{
    myBST *temp = new myBST(val);
    myBST *trav = root;
    myBST *hold = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        while (trav != NULL)
        {
            hold = trav;
            if (val > trav->data)
                trav = trav->right;
            else if (val < trav->data)
                trav = trav->left;
            else
                break;
        }
        if (val > hold->data)
        {
            hold->right = temp;
        }
        else if (val < hold->data)
        {
            hold->left = temp;
        }
        else
        {
            cout << "\nDuplicate data\n";
            free(temp);
            count--;
        }
    }
}

void myBST::inorder(myBST *r)
{
    if (r != NULL)
    {
        r->inorder(r->left);
        cout << r->data << " ";
        r->inorder(r->right);
    }
}

void myBST::preorder(myBST *r)
{
    if (r != NULL)
    {
        cout << r->data << " ";
        r->preorder(r->left);
        r->preorder(r->right);
    }
}

void myBST::postorder(myBST *r)
{
    if (r != NULL)
    {
        r->postorder(r->left);
        r->postorder(r->right);
        cout << r->data << " ";
    }
}

void myBST::smallest(myBST *r)
{
    if (r->left != NULL)
        r->smallest(r->left);
    else
        cout << "\nSmallest Element " << r->data;
}

int myBST::largest(myBST *r)
{
    if (r->right != NULL)
        r->largest(r->right);
    else
        cout << "\nLargest Element " << r->data;
}

void myBST::search(int val)
{
    myBST *temp = new myBST(val);
    myBST *trav = root;
    myBST *hold = NULL;
    int flag = 0;
    while (trav != NULL)
    {
        if (val > trav->data)
            trav = trav->right;
        else if (val < trav->data)
        {
            trav = trav->left;
        }
        else
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "\nElement " << val << " is Found";
    else
        cout << "\nElement " << val << " not found";
}

void myBST::removeNode(int val)
{
    myBST *trav = root;
    myBST *hold = root;
    bool findflag = false;
    bool isleft = false;
    while (trav != NULL)
    {
        if (trav->data > val)
        {
            hold = trav;
            trav = trav->left;
            isleft = true;
        }
        else if (trav->data < val)
        {
            hold = trav;
            trav = trav->right;
            isleft = false;
        }
        else
        {
            findflag = true;
            break;
        }
    }
    if (findflag == true)
    {
        if (trav->left == NULL && trav->right == NULL)
        {
            free(trav);
            cout << "\nElement deleted Successfully\n";
            if (isleft = true)
                hold->left = NULL;
            else
                hold->right = NULL;
        }
        else if (trav->left == NULL && trav->right != NULL)
        {
            if (isleft == true)
                hold->left = trav->right;
            else
                hold->right = trav->right;
            free(trav);
            cout << "\nElement Deleted Successfully";
        }
        else if (trav->left != NULL && trav->right == NULL)
        {
            if (isleft == true)
                hold->left = trav->left;
            else
                hold->right = trav->left;
            free(trav);
            cout << "\nElement Deleted Successfully";
        }
        else
        {
            int tempLarge = trav->left->largest(trav->left);
            root->removeNode(tempLarge);
            trav->data = tempLarge;
            cout << "\nElement Deleted Successfully";
        }
    }
    else
    {
        cout << "\nElement Not Found..\n";
    }
}

int main()
{
    root->insertNode(45);
    root->insertNode(39);
    root->insertNode(56);
    root->insertNode(12);
    root->insertNode(34);
    root->insertNode(78);
    root->insertNode(32);
    root->insertNode(10);
    root->insertNode(89);
    root->insertNode(54);
    root->insertNode(67);
    root->insertNode(81);
    cout << "\nInorder: ";
    root->inorder(root);
    cout << "\nPreorder: ";
    root->preorder(root);
    cout << "\nPostOrder: ";
    root->postorder(root);
    cout << "\n";
    root->smallest(root);
    root->largest(root);
    cout << "\n";
    root->search(99);
    root->search(45);
    cout << endl;
    cout << "\nRemoving element 5" << endl;
    root->removeNode(5);
    cout << endl;
    cout << "Removing element 54" << endl;
    root->removeNode(54);
    cout << "\nInorder: ";
    root->inorder(root);

    return 0;
}
