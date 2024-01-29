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

int ShellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return 0;
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
    ShellSort(arr, size);
    cout << "Array after sorting:";
    printArray(arr, size);
    return 0;
}