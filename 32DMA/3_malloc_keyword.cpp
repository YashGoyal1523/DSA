// // malloc- 
// The return type of the malloc function in C (and C++) is void*. This means that malloc returns a pointer (pointer to single dabba) to a memory block of the requested size, but the type of the pointer is void*, which is a generic pointer type that can be cast to any other pointer type.

// void*p=malloc(size);  // malloc returns void*

// size specifies the number of bytes to allocate.
// The function returns a void* pointer to the beginning of the allocated memory block.

// You typically cast this void* pointer to the appropriate type for use:
// int*pt=(int*)p; // explicit typecasting

// int* ptr = (int*)malloc(sizeof(int)); // Casting the void* to int*


// // new

// The return type of the new operator in C++ is a pointer (pointer to single dabba) to the type of object being allocated.

// For example:

// int* ptr = new int;  // new int returns a int*

// Here's a more detailed breakdown:

// When you use new, it allocates memory for an object of a specific type and returns a pointer to that type.
// The type of pointer returned by new corresponds to the type of object being allocated.

// For instance:

// new int returns a int*
// new double returns a double*
// new MyClass returns a MyClass*

// So, the return type of new is a pointer of the type that matches the object being allocated, and it directly represents the address of the allocated memory.



#include <iostream>

using namespace std;

void print(int **v, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // allocation in heap memory


    //  allocate int 

    // using new
    int *intPtr = new int(5); // value 5 

    // using malloc
    // void*ptr=malloc(4);
    // int *mptr=(int*)ptr;
    // *mptr=5;
    int *mptr = (int *)malloc(4);  // 4 bytes allocatd
    *mptr = 5; // value 5

    cout << *intPtr << " " << *mptr << endl;

    delete intPtr;
    free (mptr); // bracket needed



    // array allocation

    // 1D allocation

    int *arrnew = new int[5];

    // using malloc
    int *arrmalloc = (int *)malloc(5 * sizeof(int)); 

    for (int i = 0; i < 5; i++)
    {
        int d;
        cin >> d;
        arrnew[i] = arrmalloc[i] = d;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arrnew[i] << " " << arrmalloc[i] << endl;
    }
    delete[] arrnew;
    free(arrmalloc);

    // 2D allocation

    int rows = 5, cols = 5;
    int **ptr2d = new int*[rows];

    for (int i = 0; i < rows; ++i)
        ptr2d[i] = new int[cols];

    int **ptr2dmalloc = (int **)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++)
        ptr2dmalloc[i] = (int *)malloc(sizeof(int) * cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ptr2d[i][j] = 7;
            ptr2dmalloc[i][j] = 8;
        }
    }

    print(ptr2d, rows, cols);
    print(ptr2dmalloc, rows, cols);

    for (int i = 0; i < rows; ++i){
    delete[] ptr2d[i];
    }
    delete[] ptr2d;

    for (int i = 0; i < rows; ++i){
    free(ptr2dmalloc[i]);
    }
    free(ptr2dmalloc);
    return 0;
}