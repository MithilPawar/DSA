#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }
    cout << "\n";
}

void bubbleSort(int arr[], int size)
{
    int temp;
    int pas = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        pas++;
    }
    cout << pas;
}

int main()
{
    int size;
    cout << "Enter the size of array:";
    cin >> size;
    int arr[size];
    cout << "Enter the array element:";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Array before sorting:";
    printArray(arr, size);
    bubbleSort(arr, size);
    cout << "Array after sorting:";
    printArray(arr, size);

    return 0;
}