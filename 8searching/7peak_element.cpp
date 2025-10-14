//peak element

#include<iostream>          // ....<..<..increasing elements.<..< peak element >..>..decreasing elements.>....>
using namespace std ;       //              A                                              B


// note: binary search can be applied only in monotonic array.....ie either increasing or decreasing
// A , B mein laga skte





// int peak(int arr[],int n){

//     int s=0;
//     int e=n-1;
    
//     while (s<e)   //<= nhi aayega as infinite loop banjjayega last m jab single element rhjayega ya array m hi single element hai   // tip: yaad h na start=mid+1 and end=mid-1 mein <= hota  ..... jab bhi inme change kroge jse start=mid ya end=mid krdia toh isme < hoga as <= mein infinte loop dedega last mein single element rhjane pe
//     {
//        int  mid=s+(e-s)/2;
//         if (mid+1<n&&arr[mid]<arr[mid+1])
//         {
//            //mid A wali line mein hai ...->peak is in right....right aao
//             s=mid+1;
//         }
        
//         else 
//         {
//            //mid ya B line mein hai ya peak par hai...
//            e=mid;    // mid(including) se left m dekhte  ...including as yeh peak par bhi ho skta
//         }
        
//     }

// return s;   //or  //  return e;   // s==e hoga tab pahuchege yaha  // single element rhgya... yhi ans hai
// }

//OR


// int peak(int arr[],int n){

//     int s=0;
//     int e=n-1;
    
//     while (s<=e)   //<=   krdia....infinite loop nhi jaane dege as single element ka alag case daaldege      
//     {
//          if(s==e) return s;   // single element case
//        int  mid=s+(e-s)/2;
//         if (mid+1<n&&arr[mid]<arr[mid+1])
//         {
//            //mid A wali line mein hai ...->peak is in right....right aao
//             s=mid+1;
//         }
        
//         else 
//         {
//            //mid ya B line mein hai ya peak par hai...
//            e=mid;    // mid(including) se left m dekhte  ...including as yeh peak par bhi ho skta
//         }
        
//     }

// return -1;  // VSE TOH KABHI USE NHI HOGA YEH BAS KUCH TOH RETURN KRNA THA TOH KRDIA
// }

//OR

// int peak(int arr[],int n){
//       int ans = -1;
//         int s = 0;
//         int e = n-1;

//         while(s <= e){
//             int mid = (s + e) / 2;
//             if(mid+1<n&&arr[mid + 1] > arr[mid]){
//                 // mid A line m hai->right aao
//                 s = mid + 1;
//             }
//             else if(mid-1>=0&&arr[mid - 1] > arr[mid]){
//                 //mid B line m -> left aao
//                 e = mid - 1;
//             }
//             else {
//                 // mid must be Peak
//                 ans = mid;
//                 break;
//             }
//         }
//         return ans;
//     }





int main()
{ int arr[]={1,2,3,4,3,2,1};
    int n=7;
    int ansidx=peak(arr,n);
    cout<<arr[ansidx];
return 0;
}



//lc 162

// https://youtu.be/cXxmbemS6XM?si=Ed8GhOUoqKsqoRlE


class Solution {
public:

int bs(vector<int>& nums){
    int s=1;
    int e=nums.size()-2;

    while(s<=e){
        
        int mid=s+(e-s)/2;

        if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
            return mid;
        }
        else if(nums[mid]<nums[mid+1]){
            s=mid+1;
        }
        else{//nums[mid]>nums[mid+1]  //note: given hai ques m : nums[i] != nums[i + 1] for all valid i.
            e=mid-1;
        }
    }
    return -1; // VSE TOH KABHI USE NHI HOGA YEH BAS KUCH TOH RETURN KRNA THA TOH KRDIA
}


    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
     
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        

        int ans=bs(nums);
        return ans;
    }
};


