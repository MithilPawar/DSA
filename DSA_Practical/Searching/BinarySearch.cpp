#include <iostream>
using namespace std;

void binarySearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else if (arr[mid] == key)
        {
            cout << "Element found at index " << mid;
            break;
        }
        else
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
    }
    if (low > high)
    {
        cout << "Element not found";
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

    binarySearch(arr, size, key);
    return 0;
}