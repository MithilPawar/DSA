#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class BinaryMinHeap
{
public:
    int *data;
    int heapsize;
    int arraysize;
    int getleftchildindex(int indexNode)
    {
        return (2 * indexNode) + 1;
    }
    int getrightchildindex(int indexNode)
    {
        return (2 * indexNode) + 2;
    }
    int getparentindex(int indexNode)
    {
        return (indexNode - 1) / 2;
    }
    BinaryMinHeap(int size)
    {
        data = new int[size];
        heapsize = 0;
        arraysize = size;
    }
    int getMinimum()
    {
        if (isempty() == true)
        {
            cout << "Heap is empty..";
        }
        else
        {
            return data[0];
        }
    }
    void display()
    {
        cout << "\n Heap : "
             << " ";
        for (int i = 0; i < heapsize; i++)
        {
            cout << data[i] << " ";
        }
    }
    void insert(int val)
    {
        cout << "\n Inserting " << val << endl;
        if (heapsize == arraysize)
            cout << "Heap is full..";
        else
        {
            data[heapsize] = val;
            heapsize++;
            reheapUp(heapsize - 1);
        }
    }
    void reheapUp(int nodeIndex)
    {
        int parentnode, temp;
        if (nodeIndex != 0)
            ;
        {
            parentnode = getparentindex(nodeIndex);
            if (data[parentnode] > data[nodeIndex])
            {
                temp = data[parentnode];
                data[parentnode] = data[nodeIndex];
                data[nodeIndex] = temp;
                reheapUp(parentnode);
            }
        }
    }
    bool isempty()
    {
        if (heapsize == 0)
            return true;
        else
            return false;
    }
    void remove()
    {
        if (isempty() == true)
            cout << "Heap is empty..";
        else
        {
            data[0] = data[heapsize - 1];
            heapsize--;
            reheapDown(0);
        }
    }
    void reheapDown(int nodeIndex)
    {
        int leftchild, rightchild, minIndex, temp;
        leftchild = getleftchildindex(nodeIndex);
        rightchild = getrightchildindex(nodeIndex);
        if (rightchild >= heapsize)
        {
            if (leftchild >= heapsize)
                return;
            else
                minIndex = leftchild;
        }
        else
        {
            if (data[leftchild] < data[rightchild])
                minIndex = leftchild;
            else
                minIndex = rightchild;
        }
        if (data[minIndex] < data[nodeIndex])
        {
            temp = data[minIndex];
            data[minIndex] = data[nodeIndex];
            data[nodeIndex] = temp;
            reheapDown(minIndex);
        }
    }
    void sort()
    {
        cout << "\n Sorted Heap : ";
        int orgheapsize = heapsize;
        int sortedarray[heapsize], i;
        for (i = 0; i < orgheapsize; i++)
        {
            sortedarray[i] = data[0];
            cout << sortedarray[i] << " ";
            remove();
        }
    }
};
int main()
{
    BinaryMinHeap BinaryMinHeap(10);
    BinaryMinHeap.insert(70);
    cout << endl;
    BinaryMinHeap.insert(100);
    cout << endl;
    BinaryMinHeap.insert(90);
    cout << endl;
    BinaryMinHeap.insert(20);
    cout << endl;
    BinaryMinHeap.insert(50);
    cout << endl;
    BinaryMinHeap.insert(200);
    BinaryMinHeap.display();
    cout << endl;
    BinaryMinHeap.remove();
    BinaryMinHeap.display();
    cout << endl;
    BinaryMinHeap.sort();
    getch();
    return 0;
}
