// note : accumulate() fn : accumulate (position of first,position of next to last, intial sum ) :  This function returns the sum of all the values lying in range from first element to last element in a container  with some initial sum  : header file -> numeric

// note : max_element (position of first, position of next to last) :  It returns a pointer to the largest  element in the range, and in case if there are more than  one such element, then it points to the first one. : header file -> algorithm
// note : *max_element() : returns the value (dereference krdia)
// note: similarly for min_element()




// book allocation problem

// striver

//https://www.naukri.com/code360/problems/allocate-books_1090540?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTabValue=PROBLEM


// note : max is min : binary search

// search space banao , binary search lagao



// sabko atleast ek deni : if books<students : ans not possible
// for ans possible:
// note:in a case the maximum pages that a person will read can be in the range [max of array(1 book allot ho max page wali),sum of array(saari book allot)] 
// so this the search space...


// m1: shuru se linearly ek ek check krte jao and phla valid milte hi uthalo..
// m2: binary search se kr skte

// binary search

// int countStudents(vector<int> &arr, int pages) { 
//     int n = arr.size(); //size of array.
//     int students = 1;
//     long long pagesStudent = 0;
//     for (int i = 0; i < n; i++) {
//         if (pagesStudent + arr[i] <= pages) {
//             //add pages to current student
//             pagesStudent += arr[i];
//         }
//         else {
//             //add pages to next student
//             students++;
//             pagesStudent = arr[i];
//         }
//     }
//     return students;     // note : yeh method [1,sum] search space mein nhi chalega
// } 

// int findPages(vector<int>& arr, int n, int m) {
//      if (m > n) return -1;

//     int low = *max_element(arr.begin(), arr.end());
//     int high = accumulate(arr.begin(), arr.end(), 0);
//     int ans=-1;
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         int students = countStudents(arr, mid);
//         if (students > m) {
//             low = mid + 1;
//         }
//         else {
//             ans=mid;
//             high = mid - 1;
//         }
//     }
//     return ans;
// }


//note: this is wrong

//  while (low <= high) {
//         int mid = (low + high) / 2;
//         int students = countStudents(arr, mid);
//         if (students > m) {
//             low = mid + 1;
//         }
//         else if(students==m) {
//             ans=mid;
//             high = mid - 1;
//         }
//         else{
//                high = mid - 1;
//         }
//     }

// see testcase
//  [2,3,1,1,1,1,1] , m=7 ....processing mein students==m aayega hi nhi




// // note 
// // lakshay bhaiya ka soln: 

// //https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// // search space : [1,sum]   (note: uper wala method [1,sum] search space mein nhi chalega)
// class Solution
// {
// public:
//     bool canWeAllocate(int A[], int N, int M, int sol)
//     {
//         int c = 1;   // maintain count of students jitno ko allocate krdi ....phle bcho ko uthalia ...1 leliya
//         int pageSum = 0;  // maintain pages given to current student...abhi kuch nhi diya ...zero leliya
//         for (int i = 0; i < N; i++)  // ek ek book uthao
//         {
//             if (A[i] > sol)          //  book mein page  max page jo ek bacha padh skta se zyada h toh return false as yeh allocate nhi kr paayege
//             {
//                 return false;
//             }
//  //       valid book h
//             if (pageSum + A[i] > sol)  // current bche ki capacity se bahar jaare pages is book ke aane se
//             {
//                 c++;   // toh agla uthalo 
//                 if (c > M)    // agar bache over hogye toh return false
//                 {
//                     return false;
//                 }
// //       nhi toh ab isko dedo yeh book and  yeh curr bacha hai
//            pageSum = A[i];  //..currka page count update krlo
//             }
//             else      // capacity m hi hai toh dedo
//             {
//                 pageSum += A[i];
//             }
//         }
//      // yaha h(uper wala code cross krke) mtlb sab allocate hogyi and in students <=M hui h.......note: hume vse exact M mein krni...toh==M toh koi dikkat hi nhi  par for <M note : yaha h(int main ka initial if cross krlia) mtlb books>= students h for sure toh agar hum <M mein kar paare mtlb ek se zyada di hogi bcho ko ...unse cheen ke M mein krlege..outer matter h voh......toh yeh students<M wali koi dikkat nhi h...> mein dikkat thi.......toh allocatable h mtlb ....return true kro
//         return true;
//     }

//     long long findPages(int N, int A[], int M)
//     {
//         if (M > N){    // books hi students se kam h
//             return -1;    // sabko ek ek nhi de paayege
//          }
//         int start = 1;
//         int end = accumulate(A, A + N, 0);
//         long long ans = -1;
//         while (start <= end)
//         {
//             int mid = (start + end) / 2;
//             if (canWeAllocate(A, N, M, mid))  // check whether valid by checking whether we can allocate to k
//             {
//                 ans = mid; // mid par milgya mtlb aage bhi kar skte par min chahie toh aage ignore and piche dekhege kya pata kam miljaye so ek baar store krke(kya pata na ho piche) left m dhundte 
//                 end = mid - 1;
//             }
//             else              // mid pe nhi toh piche bhi nhi hoga so aage dhundho
//             {
//                 start = mid + 1;    
//             }
//         }
//         return ans;
//     }                                           // note: isme yeh initial -1 wali condition isme cover nhi hogi balki iske bina galat hojayegaa yeh code.....as uske bina < wale m kuch keh nhi skte the as hume pata nhi ki books sufficient h ya nhi for atleast 1 to students and galat shi dono true ajayege
// };
