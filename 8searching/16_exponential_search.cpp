// given sorted array ... tell index if present else -1

// exponential search / doubling search / galloping search / struzik search


// like binary search we need sorted array for exponential search

// Find range where element is present
// Do Binary Search in above found range.

#include <iostream>
using namespace std;

int bs(int a[], int start, int end, int x)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (x > a[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}


// origial
int expSearch(int a[], int n, int x)
{
    if (a[0] == x)
        return 0;

    int i = 1;
    while (i < n && a[i] <= x)
    {   
        i = i * 2; // i*=2 // i = i << 1;
    }

    return bs(a, i / 2, min(i, n - 1), x);
}

//or

// int expSearch(int a[], int n, int x)
// {
//     if (a[0] == x)
//         return 0;

//     int i = 1;
//     while (i < n && a[i] <x)    // <= nhi kiya as isme ek step extra iterate hota hai in cases jab i jump krte hue x par hi land krde.....kyuki maanlo agar x par land krdiye toh yhi pe ruk ke range lelo ....par hum code ke acc ek aur aage jaate fir jab bada milta tab krege toh ek step faaltu hogya only in this case jab x par land kre i...baakio mein same no problem.....toh < se yeh sambhal jaayega as agar x par land krdia i toh < toh nhi hua satisfy toh yhi pe ruk ke range lelege.....sirf yhi ek case m help krra voh bhi sirf ek iteration baakio m toh same h
//     {   
//         i = i * 2; 
//     }

//     return bs(a, i / 2, min(i, n - 1), x);
// }

//or


// int expSearch(int a[], int n, int x)
// {
//     if (a[0] == x)
//         return 0;

//     int i = 1;
//     while (i < n && a[i] <= x)
//     {   
//       if(a[i]==x) return i;   //<= lere toh uska faayda uthaalo // x par land hote hi return hi krdo //  isse add krne se efficiency aur bhadegi
//         i = i * 2; 
//     }

//     return bs(a, i / 2, min(i, n - 1), x);
// }

//or

// int expSearch(int a[], int n, int x)
// {
//     int i=0;
//     int j=1;
//     while (j < n && a[j] <= x)   // < bhi le skte
//     {   
//         i=j;
//         j = j * 2; 
//     }

//     return bs(a, i, min(j, n - 1), x);
// }

// or

// int expSearch(int a[], int n, int x)
// {
//     int i=0;
//     if(a[i]==x) return i;
//     int j = 1;
//     while (j < n && a[j] <= x)
//     {   
//         if(a[j]==x) return j;
//         i=j;
//         j = j * 2; 
//     }

//     return bs(a, i, min(j, n - 1), x);
// }



int main()
{
    int a[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int n = sizeof(a) / sizeof(int);
    int x = 11;
    int ans = expSearch(a, n, x);

    cout << ans;
    return 0;
}


// tc : o(2^((logm)-1))  m = search range ka ending index


// applications:
// search in infinte arrays/unbounded arrays 
// better than binary search if x is near beginning