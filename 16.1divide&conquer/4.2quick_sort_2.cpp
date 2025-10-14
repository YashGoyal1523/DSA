// lakshay bhaiya

//  another way for setting pivot (when taking last element as pivot)

#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{

    int pivot = e; //taking last element as pivot

 // setting array

    int i = s - 1;
    int j = s;
    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            ++i;
            swap(arr[i], arr[j]);
        }
        ++j;
    }

    ++i;
    // i is at the correct index position for the pivot element.
    swap(arr[i], arr[pivot]);


    // ab sab set h , pivot index return krdo

    return i; // pivot index
}

void quickSort(int arr[], int s, int e)
{

    // base case
    if (s >= e)
        return;

    // partition karenge by pivot element
    int pindex = partition(arr, s, e);

    // left part sort karo
    quickSort(arr, s, pindex - 1);

    // right wala part sort karo
    quickSort(arr, pindex + 1, e);

    return;
}

int main()
{

    int arr[10] = {2, 4, 1, 6, 9, 9, 9, 9, 9, 9};
    int n = 10;
    int s = 0;
    int e = n - 1;

    quickSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
