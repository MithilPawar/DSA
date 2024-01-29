#include <iostream>
using namespace std;
#define TABLE_SIZE 10
int h[TABLE_SIZE];

int foldBoundary(int key)
{
    int part1 = key / 100;
    int part2 = key % 100;
    int sum = part1 + part2;

    int hashedValue = sum % TABLE_SIZE;

    return hashedValue;
}

void insert()
{
    int key, index, i, flag = 0, hkey;

    cout << "Enter the value to insert into hash table \n";
    cin >> key;

    hkey = foldBoundary(key) % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i) % TABLE_SIZE;
        if (h[index] == 0)
        {
            h[index] = key;
            break;
        }
    }
    if (i == TABLE_SIZE)
    {
        cout << "Element cannot be inserted";
    }
}

void search()
{
    int key, index, i, flag = 0, hkey;

    cout << "\nEnter search element \n";
    cin >> key;
    hkey = foldBoundary(key) % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        index = (hkey + i) % TABLE_SIZE;
        if (h[index] == key)
        {
            cout << "Value is found at index " << index;
            break;
        }
    }
    if (i == TABLE_SIZE)
    {
        cout << "\nValue is not found";
    }
}

void display()
{
    int i;
    cout << "\nElements in the hash table are:";
    for (i = 0; i < TABLE_SIZE; i++)
    {
        cout << "\nAt index " << i << "\t value = " << h[i];
    }
}

int main()
{
    int opt, i;
    while (1)
    {
        cout << "\nPress 1. Insert \t 2. Display\t 3. Search\t 4. Exit \t" << endl;
        cin >> opt;

        switch (opt)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            exit(0);
        }
    }
}
