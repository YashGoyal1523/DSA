// gfg  Sum of two numbers represented as arrays
// https://www.geeksforgeeks.org/problems/sum-of-two-numbers-represented-as-arrays3110/1

// Given two numbers represented by two different arrays A and B. The task is to find the sum array. The sum array is an array representation of addition of two input arrays.
// No leading zeroes in array A and B.

// m1 : arrays ka number banake fir add krke fir array m daalna ...yeh hojayega lekin isse int ki range mein hi solve kr paaryege...agar usse bahar chale gye number fir int m store nhi kr paayege (long vagarah lena bhi acha option nhi h)

// m2 : array se hi kaam karna : works fine sabme


// class Solution{
// public:	
	
// 	vector<int> findSum(vector<int> &a, vector<int> &b) {
// 	    vector<int>ans;
// 	    reverse(a.begin(),a.end());
// 	    reverse(b.begin(),b.end());
// 	    int i=0;
// 	    int j=0;
// 	    int carry=0;
// // Process digits of a and b simultaneously
// 	    while(i<a.size()&&j<b.size()){
// 	        int sum=a[i]+b[j]+carry;
// 	        int digit=sum%10;
// 	         carry=sum/10;
// 	        ans.push_back(digit);
// 	        i++;
// 	        j++;
// 	    }
// 	    // agar b phle khaali hogya and a bachgya
// 	    while(i<a.size()){
// 	         int sum=a[i]+carry;
// 	        int digit=sum%10;
// 	         carry=sum/10;
// 	        ans.push_back(digit);
// 	        i++;
// 	    }
// 	      // agar a phle khaali hogya and b bachgya
// 	    while(j<b.size()){
// 	         int sum=b[j]+carry;
// 	        int digit=sum%10;
// 	        carry=sum/10;
// 	        ans.push_back(digit);
// 	        j++;
// 	    }
// 	    // agar kuch carry rhgya ho
// 	    if(carry!=0){
// 	        ans.push_back(carry);
// 	    }
//  //  abhi ans ulta stored h	    
// 	    reverse(ans.begin(),ans.end());
	    
// 	    return ans;
// 	}

// };


// // note initially bina reverse kre bhi kr skte..... usme piche se shuru hoke aage tak aana hoga (size-1 se >=0 ) tak ....ans vector reverse krlena as usme ulte m hi stored hoga

// // note: agar leading zeroes present h toh agar final ans m bhi leading zero chaljayega toh same lagado par agar final ans m nhi chalega toh ans vector m reverse wale step se phle piche se saare zero pop krlo fir reverse krlo 



// // note  hum  ans ko  dono array m se ek ya dono m banate hue bhi chalskte h instead of another array


// a mein banate hue chlte

// class Solution{
// public:	
	
// 	vector<int> findSum(vector<int> &a, vector<int> &b) {

// 	    reverse(a.begin(),a.end());
// 	    reverse(b.begin(),b.end());
// 	    int i=0;
// 	    int j=0;
// 	    int carry=0;
// // Process digits of a and b simultaneously
// 	    while(i<a.size()&&j<b.size()){
// 	        int sum=a[i]+b[j]+carry;
// 	        int digit=sum%10;
// 	         carry=sum/10;
// 	        a[i]=digit;
// 	        i++;
// 	        j++;
// 	    }
// 	    // agar b phle khaali hogya and a bachgya
// 	    while(i<a.size()){
// 	         int sum=a[i]+carry;
// 	        int digit=sum%10;
// 	         carry=sum/10;
// 	        a[i]=digit;
// 	        i++;
// 	    }
// 	      // agar a phle khaali hogya and b bachgya
// 	    while(j<b.size()){
// 	         int sum=b[j]+carry;
// 	        int digit=sum%10;
// 	        carry=sum/10;
// 	        a.push_back(digit);  // push hoga as index khatm a ke
// 	        j++;
// 	    }
// 	    // agar kuch carry rhgya ho
// 	    if(carry!=0){
// 	        a.push_back(carry);
// 	    }
//  //  abhi ans ulta stored h	    
// 	    reverse(a.begin(),a.end());
	    
// 	    return a;
// 	}

// };