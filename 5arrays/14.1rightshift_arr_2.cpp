// rotate array rightwards by k steps ...k is non -ve.



// method 1 - pichle ques mein jo kiya tha vhi krna hai bas k baar krdo yaani uska k baar loop chalado...ie... k baar right shift 1 krdo 
//// note: ISKO THODA OPTIMISE KAR SKTE HAI
// note : n shift ke baad toh same hi banjayega... 
// toh k>=n case k liye thoda change kr skte h
//k==n mein toh same hi krdo vaapis
//k>n mein hume uper ka remainder times shift krna h bas as har n shift ke baad toh same hi banjayega .... (use %   ... shift k%n times)



// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n=nums.size();
//         if(k==n) {        // n baar shift ke baad toh same hi banega
//             return ;
//         }
//         else{  // k>n ya k<n case
// //        note:  as n shift ke baad same banjata h toh if k>n toh hume uper ka remainder times shift krna h bas as har n shift ke baad toh same hi banjayega .....  k<n mein toh k baar hi hoga no alterations
//             int x=k%n;  // % gives remainder  // will give uper ka remainder in k>n and k in k<n // k<n mein kuch change nhi kiya toh koi dikkat nhi dera usme and >n wale ko krdia toh  dono sambhal jaayge shi hai// k>n optimise hogya
//               while(x>=1){
//             int last=nums[n-1];
//             int i=n-1;
//             while(i>=1){
//                 nums[i]=nums[i-1];
//                 i--;
//             }
//             nums[0]=last;
//             x--;
//         }
//         }
//         return ;
//     }
// };






// method 2 
// suppose size is n=6 and k=2...so after rotation element at index 0 goes to index 2...1 to 3 ...2 to 4...3 to 5...4 to 1...5 to 2.......ek element ka new index is (oldindex+k)%n...


// #include<iostream>
// using namespace std ;
// int main()
// {
//     int arr[]={1,2,3,4,5};
//     int n=5;

//     // printing array
// for (int i = 0; i < n; i++)
// {
//    cout<<arr[i]<<" ";
// }



//     int k=2;

//     int brr[n];

//     for (int index = 0; index < n; index++)            // ek new array mein arrange krlete rotated elements
//     {
//         int newindex=(index+k)%n;
//         brr[newindex]=arr[index];
//     }
    
// // ab required rotated array is present in brr par hume arr mein hi change krna tha toh ek kam krte brr ko arr mein daaldete

// for (int i = 0; i < n; i++)
// {
//    arr[i]=brr[i];
// }



// cout<<endl;


// // printing array

// for (int i = 0; i < n; i++)
// {
//    cout<<arr[i]<<" ";
// }


// return 0;
// } 


 // m3 : 
//     reverse( 0,n-1);
//     reverse( 0, k-1);
//     reverse( k,n-1);

// it will work for k<=n  // so hum k = k%n krlege taaki k>n case bhi hojaye 

// #include<iostream>
// using namespace std ;


// void reverse(int arr[], int si, int ei)
// {
//     int i = si;
//     int j = ei;
//     while (i < j)
//     {

//         int temp = arr[i];          
//         arr[i] = arr[j];
//         arr[j] = temp;
//         i++;
//         j--;
//     }
//     return;
// }


// int main()
// {
// int arr[7] = {1,2,3,4,5,6,7};
// int n = 7;  // no of elements
// int k = 50; // steps

// k = k%n; 

// reverse(arr, 0,n-1);
// reverse(arr, 0, k-1);
// reverse(arr,k,n-1);

// for(int i=0;i<=6;i++) {
//  cout<<arr[i]<<" ";
// }
// return 0;
// }


// m4 
// seedha hi k shift krdo using method jse 1 shift krre pichle ques mein...
// ie har element par jo value aayegi voh daaldo seedha
// given array ke last k elements ek baar store krlo
// ab last se n-k elements ie n-1 index se k index tak .....i index element ki value mein i-k index wale ki value daaldo
// ab shuru ke k mein voh last ke k stored daaldo

// note: it will work for k<=n so k=k%n krlege 

// #include<iostream>
// using namespace std ;

// void rotate(vector<int>& nums, int k) {
    
//     int n=nums.size();
//     k=k%n;
// vector<int>temp;

// for(int i=(n-1)-k+1;i<n;i++){
//     temp.push_back(nums[i]);
    
// }
// for(int i=n-1;i>=k;i--){
//     nums[i]=nums[i-k];
// }
// for(int i=0;i<k;i++){
//     nums[i]=temp[i];

// }
// }
// int main()
// {
//     vector<int>nums;
//     nums.push_back(1);
//     nums.push_back(2);
//     nums.push_back(3);
//     nums.push_back(4);
//     nums.push_back(5);
//     nums.push_back(6);
//     nums.push_back(7);
//     int k=1;
//     rotate(nums,k);
//     for(auto i:nums){
//         cout<<i<<" ";
//     }
// return 0;
// }

// note isko space optimise krne ke liye
// last ke k elements ek saath store krke process krne ki bajaye ...... last se ek element store krke same process krlo k times

#include<iostream>
using namespace std ;

void rotate(vector<int>& nums, int k) {
    
    int n=nums.size();
    k=k%n;
    int temp;

while(k--){

// last ka 1 element store
temp=nums[n-1];
// last se n-1 elements m process
for(int i=n-1;i>=1;i--){
nums[i]=nums[i-1];
}
// shuru ka 1 element process
nums[0]=temp;
}
}
int main()
{    vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    int k=2;
    rotate(nums,k);
    for(auto i:nums){
        cout<<i<<" ";
    }
return 0;
}



//tip : jab bhi ques esa ho ki circular manner mein kuch system chlra ho  toh soch skte ki khi (%) modulus (gives remainder)ka use toh nhi isme kuch ,ya double ended queue ka , ya doubly linked list ka , ya circular linked list ka



// % ka ek application jo questions m use ho skti

//situation-hum array ke ek index par khade h and hume steps diye h , new index chahie ...array khatm hone par ghum ke starting se shuru kro vaapis

// note : suppose kisi index par hai and  steps itne h ki hum array khatm hone se phle hi pahuchjaye ya last element tak hi pahuchna ho tab toh koi dikkat nhi aayegi nikalne mein (normal add krke nikal jaayega) par agar itne ho ki  array khatm hoke rotation krni ho par usme adding m toh array se aage chalejayege   toh uss case m % use kr skte h 
// remember: % tarike mein ...  0 based indexing chahie hoti h ..... agar 0 based na ho toh 0 based leke hi solve krna fir baad m ans mein change krnlena jse agar 1 based ho toh ans mein +1 krlena 

// method:
//case 1 :initial index is 0 ,k steps , array size n , newindex?
// isme k<n mein toh koi dikkat nhi aayegi as no rotation and seedha 0index+ksteps=k ->newindex aagya
//but for k>=n mein rotaation aayegi toh uske liye
//method 1 :effective steps
// note: n step ke baad toh yhi vaapis aajana h toh effective steps nikal lo yaani uper ka remainder nikal lo ..bas utne hi steps required hai....
// so do
// k=k%n; // isse k<n m koi adchan noi h
// new_index= k; (index after k steps from zero is k : 0+k =k)

//method 2 : effective index
//  hum kya krege ki jo array ke aage index aari uss index ka % n krdege...isse hume hamari required index (which will be within array)miljayegi jispe hum ghum ghum ke effectively aate  
// (index after k steps from zero is k:0+k=k)
// so do
// new_index=k%n; // isse k<n wale m koi dikkat noi h

// case 2 : initial any index other than 0, k steps , array size n , newindex?
// note isme esa case bhi hoga ki hume k<n mein bhi ghumna padega so
// isme effective steps wale se nhi hoga 
// so only option is effective index
// (index after k steps from curr_index  is k:currindex+k)
// do
// new_index=(curr_index+k)%n;

// case 3 : intial any index including zero index case
// use effective index
// new_index=(curr_index+k)%n;

