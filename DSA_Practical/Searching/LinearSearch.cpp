#include <iostream>
using namespace std;

void linearSearch(int arr[], int size, int key)
{
    int i = 0, pos = 0;
    while (i < size)
    {
        if (key == arr[i])
        {
            pos = i + 1;
        }
        i++;
    }
    if (pos == 0)
    {
        cout << "Element not found";
    }
    else
    {
        cout << "Element found at position " << pos;
    }
}

int main()
{
    int size, key;
    cout << "Enter the size of array:";
    cin >> size;
    int arr[size];
    cout << "Enter the array element:";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to search:";
    cin >> key;

    linearSearch(arr, size, key);
    return 0;
}