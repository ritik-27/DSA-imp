#include <iostream>
using namespace std;

struct Array
{
    int arr[10];
    int size;
    int length;
};
void display(struct Array ar)
{
    cout << "Array elements are : " << endl;
    for (int i = 0; i < ar.length; i++)
    {
        cout << ar.arr[i] << " ";
    }
    cout << endl;
}
void insert(struct Array *arr, int index, int x)
{

    if (arr->length < arr->size)
    {
        if (index >= 0 && index <= arr->length)
        {
            for (int i = arr->length; i > index; i--)
            {
                arr->arr[i] = arr->arr[i - 1];
            }
            arr->arr[index] = x;
            arr->length++;
            cout << "Length after insertion: " << arr->length << endl;
            cout << "Size of an array: " << arr->size << endl;
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

void append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->arr[arr->length] = x;
        arr->length++;
    }
    else
    {
        cout << "There's no space in an array" << endl;
    }
}

int remove(struct Array *arr, int index)
{
    int x;
    if (index >= 0 && index <= arr->length)
    {
        x = arr->arr[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->arr[i] = arr->arr[i + 1];
        }
        arr->length--;
        arr->arr[arr->length] = 0;
    }
    return x;
}

int binarysearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (h + l) / 2;
        if (key == arr.arr[mid])
        {
            return key;
        }
        else if (key < arr.arr[mid])
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

void reverse(struct Array *arr) // ? in this creating an temporary array b and copying A to B and then again copying back to A
{
    int *B;
    B = new int[arr->length];
    for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->arr[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->arr[i] = B[i];
    }
    display(*arr); // Note thiss
    // cout << "Array after reversing: " << display(arr);
}

void reverseBySwap(struct Array *arr)
{
    int temp;
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        temp = arr->arr[i];
        arr->arr[i] = arr->arr[j];
        arr->arr[j] = temp;
    }
    display(*arr);
}

void shift(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        arr->arr[i] = arr->arr[i + 1];
    }
    arr->arr[arr->length - 1] = 0;
}

void rotate(struct Array *arr)
{
    int temp = arr->arr[0];
    for (int i = 0; i < arr->length; i++)
    {
        arr->arr[i] = arr->arr[i + 1];
    }
    arr->arr[arr->length - 1] = temp;
}

void insertinsort(struct Array *arr, int x)
{
    if (arr->length == arr->size)
    {
        return;
    }
    else
    {
        cout << "old length is : " << arr->length << endl;
        int i = arr->length - 1;
        while (i >= 0 && arr->arr[i] > x)
        {
            arr->arr[i + 1] = arr->arr[i];
            i--;
        }
        arr->arr[i + 1] = x; // Note this here is i+1
        arr->length++;
        cout << "New length is : " << arr->length << endl;
    }
}

bool isSorted(struct Array *arr)
{
    for (int i = 0; i < arr->length - 1; i++)
    {
        if (arr->arr[i] > arr->arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

// * Positives on right nd negative on left.
void rearrange(struct Array *arr)
{
    int i = 0, j = arr->length - 1;
    while (i < j)
    {
        while (arr->arr[i] < 0)
        {
            i++;
        }
        while (arr->arr[j] > 0)
        {
            j--;
        }
        if (i < j)
        {
            int temp;
            temp = arr->arr[i];
            arr->arr[i] = arr->arr[j];
            arr->arr[j] = temp;
        }
    }
}

//* merge 2 sorted arrs fun
struct Array *merge(struct Array *arr1, struct Array *arr2)
{
    struct Array *arr3 = new Array[arr1->size + arr2->size];
    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->arr[i] < arr2->arr[j])
        {
            arr3->arr[k] = arr1->arr[i];
            k++, i++;
        }
        else
        {
            arr3->arr[k] = arr2->arr[j];
            k++, j++;
        }
    }
    //? to fill left alone elems
    for (; i < arr1->length; i++) // ? Note thisss
    {
        arr3->arr[k] = arr1->arr[i];
        k++;
    }
    for (; j < arr2->length; j++)
    {
        arr3->arr[k] = arr2->arr[j];
        k++;
    }
    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->size + arr2->size;
    return arr3;
}

struct Array *Union(struct Array *arr1, struct Array *arr2) // Note thisss
{
    struct Array *arr3 = new Array[arr1->size + arr2->size];
    int i = 0, j = 0, k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->arr[i] < arr2->arr[j])
        {
            arr3->arr[k] = arr1->arr[i];
            k++, i++;
        }
        else if (arr1->arr[i] > arr2->arr[j])
        {
            arr3->arr[k] = arr2->arr[j];
            k++, j++;
        }
        else
        {
            arr3->arr[k] = arr2->arr[j];
            k++, i++, j++;
        }
    }
    for (; i < arr1->length; i++)
    {
        arr3->arr[k] = arr1->arr[i];
        k++;
    }
    for (; j < arr2->length; j++)
    {
        arr3->arr[k] = arr2->arr[j];
        k++;
    }
    arr3->length = k;

    return arr3;
}

struct Array *Intersection(struct Array *arr1, struct Array *arr2) // Note thisss
{

    struct Array *arr3 = new Array[arr1->size + arr2->size];
    int i = 0, j = 0, k = 0;
    arr3->size = arr1->size + arr2->size;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->arr[i] < arr2->arr[j])
        {
            i++;
        }
        else if (arr1->arr[i] > arr2->arr[j])
        {
            j++;
        }
        else if (arr1->arr[i] = arr2->arr[j])
        {
            arr3->arr[k] = arr2->arr[j];
            k++, i++, j++;
        }
        arr3->length = k;
    }
    // cout << "length of a3: " << k << endl;
    return arr3;
}

int max(struct Array arr)
{
    int max = arr.arr[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.arr[i] > max)
        {
            max = arr.arr[i];
        }
    }
    return max;
}
int min(struct Array arr)
{
    int min = arr.arr[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.arr[i] < min)
        {
            min = arr.arr[i];
        }
    }
    return min;
}

// * Single elem  missing in sorted arr
int MissingElem(struct Array arr)
{
    int l = arr.arr[0];
    int h = arr.arr[arr.length - 1];
    int elem;
    int diff = l; //? coz elem - index(i.e 0) = elem
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.arr[i] - i != diff)
        {
            elem = i + diff; //?Note
            break;
        }
        else
        {
            elem = -1;
        }
    }
    return elem;
}

// * multiple elem  missing in sorted arr
void multimissing(struct Array arr)
{
    int l = arr.arr[0];
    int h = arr.arr[arr.length - 1];
    int diff = l;
    cout << "Missing Element is/are : " << endl;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.arr[i] - 1 != diff)
        {
            // ? Note this while loop
            while (diff < arr.arr[i] - i)
            {
                cout << i + diff << " "; // ? Note here missing value will be "i + diff"
                diff++;
            }
        }
    }
}
void multimissing2(struct Array arr) //?  Using Hashing
{
    int low = min(arr);
    int high = max(arr);
    struct Array *H = new Array[high](); //? creating an hash table or other array
    // for (int i = 0; i < high + 1; i++) //` NO need of this cause in arr dec. we have created arr of dfault elems=0
    // {
    //     H->arr[i] = 0; //? Assigning all elements of hash to 0
    // }
    for (int i = 0; i < arr.length; i++)
    {
        H->arr[arr.arr[i]] = 1; // Assiging main array's value at hash's index = 1
    }
    cout << "Elements missing are: " << endl;
    for (int i = low; i <= high; i++)
    {
        if (H->arr[i] == 0) //? Checking who are left 0, those index who are zero in hash array are missing elem in main array
        {
            cout << i << " ";
        }
    }
}

//* finding Duplicates in Sorted arr
void Duplicate(struct Array arr) //? Only Printing duplicate elems
{
    int lastDuplicate = 0;
    cout << "Duplicates elems in an array are: " << endl;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.arr[i] == arr.arr[i + 1] && arr.arr[i] != lastDuplicate) //?s this and operation is to avoid reassignment of repetead elem to lastduplicate var
        {

            lastDuplicate = arr.arr[i];
            cout << lastDuplicate << "  ";
        }
    }
}
void DuplicateCounter(struct Array arr) //? prinintg duplicate elems and its count
{
    int lastDuplicate = 0;
    cout << "Duplicates elems in an array are: " << endl;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.arr[i] == arr.arr[i + 1] && arr.arr[i] != lastDuplicate)
        {
            int j = i + 1;
            while (arr.arr[j] == arr.arr[i])
            {
                j++;
            }
            lastDuplicate = arr.arr[i];
            cout << lastDuplicate << ":" << j - i << " times." << endl;
            i = j - 1;
        }
    }
}
void DuplicateCounter2(struct Array arr) //? Duplicate Counter using HASHING
{
    int low = min(arr);
    int high = max(arr);
    struct Array *H = new Array[high](); // creating an hash table or other array

    for (int i = 0; i < arr.length; i++)
    {
        H->arr[arr.arr[i]]++; //? Assiging main array's value at hash's index = 1
    }

    cout << "Duplicates elems in an array are: " << endl;
    for (int i = 0; i <= high; i++)
    {
        if (H->arr[i] > 1) // Checking who are left 0, those index who are zero in hash array are repeated in main array
        {
            cout << i << ":" << H->arr[i] << " times." << endl;
        }
    }
}

//* finding Duplicates in UNSorted arr
void DuplicateinUnsorted(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        int count = 1;
        if (arr.arr[i] != -1)
        {
            for (int j = i + 1; j < arr.length; j++)
            {
                if (arr.arr[i] == arr.arr[j])
                {
                    count++;
                    arr.arr[j] = -1; //? whenever duplicate is found make tht elem as -1
                }
            }
            if (count > 1)
            {
                cout << arr.arr[i] << ":" << count << " times." << endl;
            }
        }
    }
}

//* Find pair with sum k(a+b=k)
void FindPair(struct Array arr, int k)
{
    for (int i = 0; i < arr.length; i++)
    {
        for (int j = i + 1; j < arr.length; j++)
        {
            if (arr.arr[i] + arr.arr[j] == k)
            {
                cout << arr.arr[i] << " + " << arr.arr[j] << " = " << k << endl;
            }
        }
    }
}
void FindPair2(struct Array arr, int k) //? using Hashing
{
    int low = min(arr);
    int high = max(arr);
    struct Array *H = new Array[high](); // creating an hash table or other array
    // for (int i = 0; i < high + 1; i++)
    // {
    //     H->arr[i] = 0; // Assigning all elements of hash to 0
    // }
    for (int i = 0; i < arr.length; i++)
    {
        if (H->arr[k - arr.arr[i]] != 0)
        {
            cout << arr.arr[i] << " + " << k - arr.arr[i] << " = " << k << endl;
        }
        H->arr[arr.arr[i]]++;
    }
}

// Find pair in sorted array
void FindPairinsorted(struct Array arr, int k)
{
    int i = 0;
    int j = arr.length - 1;
    while (i < j)
    {
        if (arr.arr[i] + arr.arr[j] > k)
        {

            j--;
        }
        else if (arr.arr[i] + arr.arr[j] < k)
        {
            i++;
        }
        else if (arr.arr[i] + arr.arr[j] == k)
        {
            cout << arr.arr[i] << " + " << arr.arr[j] << " = " << k << endl;
            j--, i++;
        }
    }
}
int minmax(struct Array arr)
{
    int min = arr.arr[0];
    int max = arr.arr[0];
    int i = 1;
    while (i < arr.length)
    {
        if (arr.arr[i] < min)
        {
            min = arr.arr[i];
            i++;
        }
        else if (arr.arr[i] > max)
        {
            max = arr.arr[i];
            i++;
        }
        else
        {
            i++;
        }
    }
    cout << "max= " << max << " min= " << min << endl;
    return min, max;
}

int main()
{
    // struct Array arr = {{11, 33, 44, 55, 66, 77}, 10, 6};

    //*Appending(at last) given elems
    // append(&arr, 63);
    // append(&arr, 65);
    // cout << " Size: " << arr.size << " length: " << arr.length << endl;

    //*Insert at given index
    // insert(&arr, 0, 10);
    //  insert(&arr, 5, 11);
    //  insert(&arr, 6, 12);
    // insert(&arr, 7, 13);
    // insert(&arr, 8, 14);

    // int remelem = remove(&arr, 4);
    // cout << "removed element " << remelem << endl;

    //*Binary srch
    // int result = binarysearch(arr, 24);
    // if (result == -1)
    // {
    //     cout << "Entered element is not in the array" << endl;
    // }
    // else
    // {
    //     cout << "Element founded at index: " << result;
    // }

    //*Reversing with help of auxiliary arr
    // cout << "Before reversing: " << endl;
    // display(arr);
    // cout << "After reversing : " << endl;
    // reverse(&arr);
    // display(arr);

    //*Reversing by Swapping
    // cout << "Before reversing: " << endl;
    // display(arr);
    // cout << "After reversing : " << endl;
    // reverseBySwap(&arr);

    //* ROtating / Shifting arrs
    // shift(&arr);
    // display(arr);
    // rotate(&arr);
    // display(arr);

    //* Inserting in sorted arr
    //  insertinsort(&arr, 37);
    //  display(arr);

    //*Checing whether arr is sorted or not
    // if (isSorted(&arr))
    // {
    //     cout << "Given array is sorted" << endl;
    // }
    // else
    // {
    //     cout << "Given array is NOT sorted" << endl;
    // }

    //*Re arranging positives nd negatives
    // rearrange(&arr);
    // display(arr);

    // *merge 2 arrs.
    // struct Array arr1 = {{2, 6, 10, 15, 16}, 10, 5};
    // struct Array arr2 = {{3, 4, 15, 18, 20}, 10, 5};
    // struct Array *arr3;
    // arr3 = merge(&arr1, &arr2);
    // display(*arr3);

    //* Union of 2 arrays
    // struct Array arr1 = {{1, 4}, 10, 2};
    // struct Array arr2 = {{2, 5}, 10, 2};
    // struct Array *arr3;
    // arr3 = Union(&arr1, &arr2);
    // display(*arr3);

    //* Intersection of 2 arrays
    // struct Array arr1 = {{2, 6, 10, 15, 18}, 10, 5};
    // struct Array arr2 = {{3, 6, 15, 18, 20}, 10, 5};
    // struct Array *arr3;
    // arr3 = Intersection(&arr1, &arr2);
    // display(*arr3);

    //* Missing Single elem in sorted arr
    // struct Array arr = {{11, 12, 13, 14, 15, 16, 17, 18}, 10, 8};
    // int elem = MissingElem(arr);
    // cout << "Element missing in arr is : " << elem << endl;

    //* Missing Multiple elem in sorted arr
    // struct Array arr = {{11, 12, 13, 14, 16, 18, 22, 25}, 10, 8};
    // // multimissing(arr);
    // // struct Array arr = {{11, 13, 14, 16, 18, 22, 25}, 10, 7};
    // multimissing2(arr); // ?Hashing

    //*Finding Duplicates in sorted arr
    // struct Array arr = {{11, 13, 13, 16, 18, 18, 25, 25}, 10, 8};
    // Duplicate(arr);
    // struct Array arr = {{11, 13, 13, 13, 18, 18, 18, 25, 25}, 10, 9};
    // DuplicateCounter(arr);
    // struct Array arr = {{12, 12, 13, 13, 18, 18, 18, 25, 25}, 10, 9};
    // DuplicateCounter2(arr); //?Hashing

    //*Finding Duplicates in UNsorted arr
    struct Array arr = {{32, 25, 13, 23, 18, 18, 18, 32, 25}, 10, 9};
    DuplicateinUnsorted(arr);

    //* Finiding pairs(in UNSORTED) that make sum equal to provided sum as second param
    // struct Array arr = {{6, 9, 5, 4, 3, 7}, 10, 6};
    // FindPair(arr, 11);
    // struct Array arr = {{6, 9, 5, 4, 3, 7}, 10, 6};
    // FindPair(arr, 10); //?hashing

    //* Finiding pairs(in UNSORTED) {SUM of 2 ==param}
    // struct Array arr = {{1, 3, 4, 4, 7, 8}, 10, 6};
    // FindPairinsorted(arr, 8); //? hashing

    // struct Array arr = {{1, 33, 4, 5, -7, 8}, 10, 6};
    // minmax(arr);
    return 0;
}