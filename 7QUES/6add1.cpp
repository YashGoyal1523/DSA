// The array-form of an integer num is an array representing its digits in left to right order.
// For example, for num = 1321, the array form is [1,3,2,1].
// Given num, the array-form of an integer, return the array-form of the integer num + 1.
// num doesnt contain leading zero


// note : m1 :array se number banake usme add krke vaapis array mein daalke krna ho skta lekin usme sirf int ki range mein solve kr paaryege...agar usse bahar chale gye number fir int m store nhi kr paayege (long vagarah lena bhi acha option nhi h)

// m2 : array se hi kaam karna : works fine sabme


    // vector<int> addToArrayForm(vector<int>& num) {
    //     vector<int>ans;
    //     reverse(num.begin(),num.end());
    //     int i=0;
    //     int carry=1; // intial carry m 1 leliya  instead of 0 taaki aage wale code m 1 add ki dikkat na ho as yeh sirf ek baari hi hoga for first element and baakio m sirf carry and element hoga th voh ek baari wala initial carry m daaldiya
    //     while(i<num.size()){
    //         int sum=num[i]+carry;
    //         int digit=sum%10;
    //         carry=sum/10;
    //         ans.push_back(digit);
    //         i++;
    //     }
    //     // agar carry zero nhi hua toh daaldo
    //     if(carry!=0){
    //          ans.push_back(carry);
    //     }
    //     // abhi ulta ans stored hai
    //     reverse(ans.begin(),ans.end());

    //     return ans;
    // }

// initial bina reverse kre bhi kar skte



// note: uper wale mein hum new array m ans banare....usi m bhi bana skte

    // vector<int> addToArrayForm(vector<int>& num) {
    //     reverse(num.begin(),num.end());
    //     int i=0;
    //     int carry=1; // intial carry m 1 leliya  instead of 0 taaki aage wale code m 1 add ki dikkat na ho as yeh sirf ek baari hi hoga for first element and baakio m sirf carry and element hoga th voh ek baari wala initial carry m daaldiya
    //     while(i<num.size()){
    //         int sum=num[i]+carry;
    //         int digit=sum%10;
    //         carry=sum/10;
    //         num[i]=digit;
    //         i++;
    //     }
    //     // agar carry zero nhi hua toh daaldo
    //     if(carry!=0){
    //          num.push_back(carry);
    //     }
    //     // abhi ulta ans stored hai
    //     reverse(num.begin(),num.end());

    //     return num;
    // }


// usi m banane mein hume ...initial bina reverse kre and piche se aage aate hue nhi kar skte as usme last carry m dikkat ho skti as start m puch nhi kr skte



