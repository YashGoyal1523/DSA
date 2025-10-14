


//pivot element : max element in a rotated and sorted array (sorted array mein right shifts krdie ) (unique elements)


// linear search :o(n)
// sort :o(nlogn)


//binary search : o(logn)


#include<iostream>
using namespace std ;


int pivotidx(int arr[],int n)
{
int s=0;
int e=n-1;
while (s<=e)
{       
    int mid=s+(e-s)/2;

    if (s==e)   //single element // corner case
    {
        return s;
    }
    
    if(mid+1<n&&arr[mid]>arr[mid+1])     // && ke phle wala for case like [1,3] ...isme mid+1 range ke bahar jaa skte ...toh andar wale hi le isiliye lagadi
    return mid;
   else if (mid-1>=0&&arr[mid]<arr[mid-1])  // && ke phle wala for case like [1,3] ...isme mid-1 range ke bahar jaa skte ...toh andar wale hi le isiliye lagadi
   return mid-1;
    else if (arr[s]>arr[mid])
    e=mid-1;
    else // arr[s]<arr[mid]
    s=mid+1;
     
}

return -1;  // vse toh yeh kabhi use hi nhi hogi par kuch toh return krna tha toh likdia

}



int main()
{
    int arr[]={1,2};
    int n=2;
    int idx=pivotidx(arr,n);
    cout<<idx;      // element is arr[idx]
return 0;
}



// note : yeh pivot function mein ...bahar wala return -1 kabhi use hi na hoga...isko thoda modify ese kr skte
int pivotidx(vector<int>& nums) {
    int s = 0, e = nums.size() - 1;

    while (s < e) {
        int mid = s + (e - s) / 2;

        // If mid element is greater than next element, mid is pivot
        if (mid+1<nums.size()&&nums[mid] > nums[mid + 1])
            return mid;

        // If mid element is less than previous element, mid-1 is pivot
        if (mid - 1 >= 0 && nums[mid] < nums[mid - 1])
            return mid - 1;

        // Decide which half to search
        if (nums[s] < nums[mid]) {
            // Pivot must be in right half
            s = mid + 1;
        } else { // nums[s]>nums[mid]
            // Pivot must be in left half
            e = mid - 1;
        }
    }

    // s == e, it must be the pivot
    return s;
}











// note:
// if you don't use brackets (curly braces {}) after an if statement, only the immediate  statement next to it is considered to be inside the if statement.

// if (condition)
//     statement1;
//     statement2;
// In this case, only statement1 will be executed if condition is true. statement2 will always be executed, regardless of the condition, because it is not included in the if statement due to the lack of brackets.

// if (condition) statement1;
// statement2;
// statement1 will be executed if condition is true.
// statement2 will be executed regardless of the condition.

// if (condition) statement1; statement2;
// statement1 will be executed if condition is true.
// statement2 will always be executed because it is not included in the if statement.
