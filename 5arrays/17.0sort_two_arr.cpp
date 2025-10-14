// given two sorted arrays....sort them into one  separate sorted array 


// method 1 - dono array ko third me daalke sort krdege

// #include<iostream>
// using namespace std; 
  

// void sortedMerge(int a[], int b[], int res[],int n, int m) 

// { 
//     // Concatenate two arrays in ans wala array
//     int i = 0, j = 0, k = 0; 
//     while (i < n) { 
//         res[k] = a[i]; 
//         i += 1; 
//         k += 1; 
//     } 
//     while (j < m) { 
//         res[k] = b[j]; 
//         j += 1; 
//         k += 1; 
//     } 
  
//     // sorting the res array 
//     sort(res, res + n + m); 
// } 
  

// int main() 
// { 
//     int a[] = { 5, 10, 15 }; 
//     int b[] = { 1, 3, 4, 12 }; 
//     int n = sizeof(a) / sizeof(a[0]); 
//     int m = sizeof(b) / sizeof(b[0]); 
  
//     // ans wala array
//     int res[n + m]; 
//     sortedMerge(a, b, res, n, m); 
  
//     cout << "Sorted merged array :"; 
//     for (int i = 0; i < n + m; i++) 
//         cout << " " << res[i]; 
    
  
//     return 0; 
// } 





// method 2 : two pointer            tc :o(m+n)

// Create an array arr3[] of size n1 + n2.
// Simultaneously traverse arr1[] and arr2[]. 
// Pick smaller of current elements in arr1[] and arr2[], copy this smaller element to next position in arr3[] and move ahead in arr3[] and the array whose element is picked.
// do it jbtak koi array khatm na hojaye
//dono khatm toh okayy varna agar ek hua h toh
// khatm se dusre wale mein ke remaining elements ko copy in arr3[].

#include<iostream>
using namespace std ;

void sortedMerge(int a[], int b[], int res[],int n, int m) 
{ 
    int i = 0, j = 0, k = 0; 

// koi ek ya dono khatm hone tak kro process
    while (i < n && j < m) { 
        if (a[i] <= b[j]) { 
            res[k] = a[i]; 
            i ++;  
            k ++; 
        }
         else { 
            res[k] = b[j]; 
            j++; 
            k++; 
        } 
    }     

// koi ek khatm ya dono khatm hogye

// agar dono khatm hogye  toh yeh dono loop  nhi chalege niche wale
// agar a[] khatm and b[] bacha  toh dusra chaljayega
// agar b[] khatm and a[] bacha  toh phla chaljayega



//  if(i<n){        //agar b[] khatm and a[] bacha h
    while (i < n) {   
        res[k] = a[i]; 
        i += 1; 
        k += 1; 
    }     
// }          // yeh if wala likhne ki no need seedha loop wala likhlo


// if(j<m){   // agar a[] khatm and b[] bacha h
    while (j < m) {   
        res[k] = b[j]; 
        j += 1; 
        k += 1; 
    }
//}            // yeh if wala likhne ki no need seedha loop wala likhlo






// note : yeh poore logic ko likhne ka another way


    // while(i<n || j<m){
    //     if(i==n){
    //         res[k] = b[j]; 
    //         j++; 
    //         k++; 
    //     }
    //     else if(j==m){
    //         res[k] = a[i]; 
    //     i += 1; 
    //     k += 1; 
    //     }
    //     else{
    //          if (a[i] <= b[j]) { 
    //         res[k] = a[i]; 
    //         i ++;  
    //         k ++; 
    //     } else { 
    //         res[k] = b[j]; 
    //         j ++; 
    //         k++; 
    //     } 
    //     }
    // }



} 
  

int main()
{   int a[] = { 5, 10, 15 }; 
    int b[] = { 2, 3, 11, 12 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    int m = sizeof(b) / sizeof(b[0]); 
  
    // Final merge list 
    int res[n + m]; 
  
    sortedMerge(a, b, res, n, m); 

    for(int i=0;i<n+m;i++){
        cout<<res[i]<<" ";
    }
return 0;
}

// note yeh teesre vector ko phle se hi n+m size ka banake k pointer chalane ki no need...seedha vector banake ..push_back kr skte....




// given two unsorted arrays...merge them in separate one sorted array 
// m1 : concatenate in third and sort
// m2: sort them individually then apply two pointer