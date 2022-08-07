#include <iostream>
#include <cstdio>
using namespace std;

class Array
{
private:
    int *arr;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        arr = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        arr = new int[size];
    }
    ~Array()
    {
        delete[] arr;
    }

    void display();
    void insert(int index, int x);
    void append(int x);
    int remove(int index);
    int binarysearch(int key);
    void reverse();
    void reverseBySwap();
    void shift();
    void rotate();
    void insertinsort(int x);
    bool isSorted();
    void rearrange();
    Array *merge(Array arr2);
    Array *Union(Array arr2);
    Array *Intersection(Array arr2);
};

void Array ::display()
{
    cout << "Array elements are : " << endl;
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Array ::insert(int index, int x)
{

    if (length < size)
    {
        if (index >= 0 && index <= length)
        {
            for (int i = length; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = x;
            length++;
            // cout << "Length after insertion: " << length << endl;
            // cout << "Size of an array: " << size << endl;
            cout << "Element added Successfully!!!" << endl;
        }
        else
        {
            cout << "please give proper index" << endl;
        }
    }
    else
    {
        cout << "There's No space in an array for " << x << endl;
    }
}

void Array ::append(int x)
{
    if (length < size)
    {
        arr[length] = x;
        length++;
    }
    else
    {
        cout << "There's no space in an array" << endl;
    }
}

int Array ::remove(int index)
{
    int x;
    if (index >= 0 && index <= length)
    {
        x = arr[index];
        for (int i = index; i < length - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        length--;
        arr[length] = 0;
    }
    return x;
}

int Array ::binarysearch(int key)
{
    int l, mid, h;
    l = 0;
    h = length - 1;
    while (l <= h)
    {
        mid = (h + l) / 2;
        if (key == arr[mid])
        {
            return key;
        }
        else if (key < arr[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

void Array ::reverse() // int this creating an temporary array b and copying A to B and then again copying back to A
{
    int *B;
    B = new int[length];
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr[i];
    }
    for (int i = 0; i < length; i++)
    {
        arr[i] = B[i];
    }
    // cout << "Array after reversing: " << display(arr);
}

void Array ::reverseBySwap()
{
    int temp;
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void Array ::shift()
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[length - 1] = 0;
}

void Array ::rotate()
{
    int temp = arr[0];
    for (int i = 0; i < length; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[length - 1] = temp;
}

void Array ::insertinsort(int x)
{
    if (length == size)
    {
        return;
    }
    else
    {
        cout << "old length is : " << length << endl;
        int i = length - 1;
        while (i >= 0 && arr[i] > x)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = x; // Note this here is i+1
        length++;
        cout << "New length is : " << length << endl;
    }
}

bool Array ::isSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

void Array ::rearrange()
{
    int i = 0, j = length - 1;
    while (i < j)
    {
        while (arr[i] < 0)
        {
            i++;
        }
        while (arr[j] > 0)
        {
            j--;
        }
        if (i < j)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

// Note this merge fun
Array *Array ::merge(Array arr2) // Note thisss
{
    Array *arr3 = new Array[length + arr2.length];
    int i = 0, j = 0, k = 0;
    while (i < length && j < arr2.length)
    {
        if (arr[i] < arr2.arr[j])
        {
            arr3->arr[k] = arr[i];
            k++, i++;
        }
        else
        {
            arr3->arr[k] = arr2.arr[j];
            k++, j++;
        }
    }
    for (; i < length; i++)
    {
        arr3->arr[k] = arr[i];
        k++;
    }
    for (; j < arr2.length; j++)
    {
        arr3->arr[k] = arr2.arr[j];
        k++;
    }
    arr3->length = length + arr2.length;
    return arr3;
}

Array *Array ::Union(Array arr2) // Note thisss
{
    Array *arr3 = new Array[length + arr2.length];
    int i = 0, j = 0, k = 0;
    while (i < length && j < arr2.length)
    {
        if (arr[i] < arr2.arr[j])
        {
            arr3->arr[k] = arr[i];
            k++, i++;
        }
        else if (arr[i] > arr2.arr[j])
        {
            arr3->arr[k] = arr2.arr[j];
            k++, j++;
        }
        else
        {
            arr3->arr[k] = arr2.arr[j];
            k++, j++;
        }
    }
    for (; i < length; i++)
    {
        arr3->arr[k] = arr[i];
        k++;
    }
    for (; j < arr2.length; j++)
    {
        arr3->arr[k] = arr2.arr[j];
        k++;
    }
    arr3->length = length + arr2.length;

    return arr3;
}

Array *Array ::Intersection(Array arr2) // Note thisss
{
    Array *arr3 = new Array[length + arr2.length];
    int i = 0, j = 0, k = 0;
    while (i < length && j < arr2.length)
    {
        if (arr[i] < arr2.arr[j])
        {
            k++, i++;
        }
        else if (arr[i] > arr2.arr[j])
        {
            k++, j++;
        }
        else
        {
            arr3->arr[k] = arr2.arr[j];
            k++, j++;
        }
    }
    // cout << "length of a3: " << k << endl;
    return arr3;
}

int main()
{
    Array *arr1;
    int ch, sz;
    int x, index;

    cout << "Enter Size of an array: ";
    scanf("%d", &sz);

    arr1 = new Array[sz];

    do
    {
        cout << "\n-----------Menu-----------\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Reverse\n";
        cout << "5. Rotate\n";
        cout << "6. Display\n";
        cout << "7.Exit\n";

        cout << "Enter Your Choice: ";
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case 1:
            cout << "Enter an element and index: ";
            cin >> x >> index;
            arr1->insert(index, x);
            break;
        case 2:
            cout << "Enter index : ";
            cin >> index;
            x = arr1->remove(index);
            cout << "Deleted Element is: " << x;
            break;
        case 3:
            cout << "Enter element to search : ";
            cin >> x;
            index = arr1->binarysearch(x);
            cout << "Element found at index : " << index;
            break;
        case 4:
            arr1->reverse();
            cout << "Array Reversed !!! " << endl;
            ;
            cout << "New Reversed ";
            arr1->display();
            break;
        case 5:
            arr1->rotate();
            cout << "Array Rotated !!! " << endl;
            cout << "New Rotated ";
            arr1->display();
            break;
        case 6:
            arr1->display();
            break;

        default:
            break;
        }
    } while (ch < 7);

    return 0;
}