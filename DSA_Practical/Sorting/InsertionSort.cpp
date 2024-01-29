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

void insertionSort(int arr[], int size)
{
    int temp, j;
    for (int i = 1; i < size; ++i)
    {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
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
    insertionSort(arr, size);
    cout << "Array after sorting:";
    printArray(arr, size);

    return 0;
}