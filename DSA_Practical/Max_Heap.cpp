#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
class BinaryMaxHeap
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
    BinaryMaxHeap(int size)
    {
        data = new int[size];
        heapsize = 0;
        arraysize = size;
    }
    int getMaximum()
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
        for (int i = 0; i < heapsize; i++)
        {
            cout << data[i] << " ";
        }
        cout << "\n";
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
            if (data[parentnode] < data[nodeIndex])
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
            cout << "\n Deleting" << data[0] << endl;
            data[0] = data[heapsize - 1];
            heapsize--;
            reheapDown(0);
        }
    }
    void reheapDown(int nodeIndex)
    {
        int leftchild, rightchild, maxIndex, temp;
        leftchild = getleftchildindex(nodeIndex);
        rightchild = getrightchildindex(nodeIndex);
        if (rightchild >= heapsize)
        {
            if (leftchild >= heapsize)
                return;
            else
                maxIndex = leftchild;
        }
        else
        {
            if (data[leftchild] > data[rightchild])
                maxIndex = leftchild;
            else
                maxIndex = rightchild;
        }
        if (data[maxIndex] > data[nodeIndex])
        {
            temp = data[maxIndex];
            data[maxIndex] = data[nodeIndex];
            data[nodeIndex] = temp;
            reheapDown(maxIndex);
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
    BinaryMaxHeap BinaryMaxHeap(10);
    BinaryMaxHeap.insert(70);
    cout << endl;
    BinaryMaxHeap.insert(100);
    cout << endl;
    BinaryMaxHeap.insert(90);
    cout << endl;
    BinaryMaxHeap.insert(20);
    cout << endl;
    BinaryMaxHeap.insert(50);
    cout << endl;
    BinaryMaxHeap.insert(200);
    BinaryMaxHeap.display();
    cout << endl;
    BinaryMaxHeap.remove();
    BinaryMaxHeap.display();
    cout << endl;
    BinaryMaxHeap.sort();
    getch();
    return 0;
}
