#include <iostream>
using namespace std;

int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void countSort(int arr[], int size, int place)
{
    int output[size + 1];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void radixsort(int arr[], int size)
{

    int max = getMax(arr, size);

    for (int place = 1; max / place > 0; place *= 10)
    {
        countSort(arr, size, place);
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    display(arr, size);
    radixsort(arr, size);
    cout << "Array after sorting:";
    display(arr, size);
    return 0;
}