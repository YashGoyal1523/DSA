// given an array . remove its duplicate elements

#include<iostream>
using namespace std ;

// order change 
void remove(vector<int>&nums){     // by reference
    
    vector<int>temp;  // isme ans array banayege baad mein original mein copy krdege isko
    
    sort(nums.begin(),nums.end());  //  array ko sort krdo

    temp.push_back(nums[0]);  // phla element toh daaldo temp mein
    // ab baakio ke liye uske piche wale se dekhte hue chalo // if piche wale ke equal nahi h toh temp mein daldo vrna aage bhado
    for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){  
                temp.push_back(nums[i]);
            }
    }
    nums=temp;

    return;
}

int main()
{
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1); //{2,4,1,2,1}
    remove(nums);

    for(auto i:nums){
        cout<<i<<" ";
    }
return 0;
}

//order no change
// m1: shuru se start hoke chlte jaayge and map mein present mark krte jaayege and jo present nhi h usse temp array m daalte jaayege....last m temp copy krdege original m
// m2 : shuru se start hoke chlte jaayge and map mein present mark krte jaayege and jo present h usse erase() krte jaayege....last m krna ho toh shrink() krlena



// note inme extra space lagri h