// find element in an infinite sorted array 

// note: we do not know ending index



//  linear search
// normally hum loop 0 se n tak m chlate par yaha
// ending index noi pata par sorted h isiliye kar paayege 

// int ls(int arr[],int x){
// int i=0;
// while(1){   // infinite loop    
//     if(arr[i]>x){
//         break;              
//     }
//     if(arr[i]==x){
//         return i;
//     }
//     i++;
// }
// return -1;
// }

// //or 

// int ls(int arr[],int x){
// int i=0;
// while(arr[i]<=x){    

//     if(arr[i]==x){
//         return i;
//     }
//     i++;
// }
// return -1;
// }

// //or

// int ls(int arr[],int x){

// for(int i=0;   ;i++){     // infinite loop    
//     if(arr[i]>x){
//         break;              
//     }
//     if(arr[i]==x){
//         return i;
//     }
// }
// return -1;
// }


//  //or


// int ls(int arr[],int x){

// for(int i=0;arr[i]<=x;i++){     
//     if(arr[i]==x){
//         return i;
//     }
// }
// return -1;
// }


// note agar target element present noi ho and usse bada bhi present nhi ho fir yeh loops wont terminate and infinitely chlta rhega and theoretically chlta hi rhega without error as array bhi infinite hi h but practically memory storage khatm hoke error de dega ya processing time se error de dega

// note yeh wale linear search hum normal bounded array m bhi likh skte..(sorted)....bas usme tab likh paayege jab hume pata ho ki target element se bada present h array m as agar target element present nhi and bada bhi present nhi toh yeh chlta rhega and wont terminate and last m array ke bahar jaake out of boound access m error de dega



// binary search toh nhi laga skte when ending index noi pta


// exponential search


// int binarySearch(int arr[], int left, int right, int x) {
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (arr[mid] == x) {
//             return mid;
//         }
//         if (arr[mid] < x) {
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//     }
//     return -1;  // Element not found
// }

// int exponentialSearch(int arr[], int x) {
//     if (arr[0] == x) {
//         return 0;
//     }
//     int i = 1;
//     while (arr[i] < x) {
//         i *= 2;
//     }
//     return binarySearch(arr, i / 2, i, x);
// }

// note agar target element present noi ho and usse bada bhi present nhi ho fir yeh loop wont terminate and infinitely chlta rhega
