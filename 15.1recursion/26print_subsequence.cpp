// print subsequences of a string

// method- include/exclude

//way 1- subsequence direct print

// #include <iostream>
// #include<vector>
// using namespace std;


// void findSubsequences(string str, string output, int index) {
// 	//base case
// 	if(index >= str.length()) {
// 		// ans jo h , vo output string me build ho chuka h 
// 		// print krdo
// 		cout <<"->" << output << endl;
// 		return;
// 	}

// 	char ch = str[index];

//     //exclude
// 	findSubsequences(str, output, index+1);
// 	//include
// 	//output string me ch character ko include krdo
// 	output.push_back(ch);
// 	findSubsequences(str, output, index+1);


//     //or


// 	// //include
//  // //output string me ch character ko include krdo
// 	// output.push_back(ch);
// 	// findSubsequences(str, output, index+1);
// 	// //exclude
// 	// output.pop_back();   //include ke liye push krdia tha toh uska remove krna pdega //backtrack 
// 	// findSubsequences(str, output, index+1);
	
   
	
//     return;
// }

// int main() {

// 	string str = "abc";
// 	string output = "";
// 	int index = 0;
// 	findSubsequences(str, output, index);

// 	return 0;
// }



// way 2 - vector m saare subsequence store phle fir  print

#include <iostream>
#include<vector>
using namespace std;

void findSubsequences(string str, string output, int index, vector<string>& ans) {
	//base case
	if(index >= str.length()) {
		//ans jo h , vo output string me build ho chuka h 
		//push krdo
		ans.push_back(output);
		return;
	}

	char ch = str[index];

	// //include
    // //output string me ch character ko include krdo
	// output.push_back(ch);
	// findSubsequences(str, output, index+1, ans);
	// //exclude
	// output.pop_back(); // include ke liye push krdia tha voh nikalna pdega // backtrack
	// findSubsequences(str, output, index+1, ans);
	

    // or

	//exclude
	findSubsequences(str, output, index+1,ans);
	//include
	//output string me ch character ko include krdo
	output.push_back(ch);
	findSubsequences(str, output, index+1,ans);
	


	return;
}


// note yeh upr walo m agar phle include baad m exclude kre toh output by ref ya by val dono chaljhaega...lekin agar phle exclude baad m include krege toh output sirf by val chalega 

// note : agar ese kre 

	// //exclude
	// findSubsequences(str, output, index+1,ans);
	// //include
	// output.push_back(ch);
	// findSubsequences(str, output, index+1,ans);
	// output.pop_back();

	//  yeh bhi shi chalega and isme by ref by val dono chaljayega

	

int main() {

	string str = "abc";
	string output = "";
	int index = 0;
	vector<string> ans;
	findSubsequences(str, output, index, ans);


	cout << "printing the subsequences in vector: " << endl;
	for(string s: ans) {
		cout << "-> " << s << endl;
	}
	
	return 0;
}


// recursion se alag method - bitmasking method
// print all subsequences of a string        (subsequence - all possible combinations of elements) ......(substring/subarray- all possible  combinations of adjacent elements)
// no of subsequences of string of length n is 2^n



// note :  subsequences ka binary representation ->....... maanlo string abc ke banare toh iske hoge a, b, c, ab, bc, ac, abc, empty .....har subsequence m jo ch included h uska corr bit 1 lelo jo include nhi kiye voh 0 ....ese uska binary form miljayega.. so a is 100 b is 010 ab is 110 and so on.... ....
//note: there are 2^n subsequences for length n ...... note: the binary numbers formed of subsequnces will be of decimal values 0 to 2^n -1 (2^n numbers)
#include <iostream>
#include<vector>
using namespace std;

void getSubsequences(string str) {
	int n = str.length();
	vector<string> ans;
	for(int num = 0; num < (1<<n); num++ ) {  //ek ek krke saare subsequences uthayege unke binary form mein     // 1<<n gives 2^n
		//subsequence ka corr number is ready
        //number num ke set bit ke corresponding ch ko include krlo

		//hum string m ek ek index pe traverse krege and uske corr bit check krege..if set toh char include
		string temp = "";
		for(int i=0; i<n; i++) {
			//i -> represent string index
			char ch = str[i];
			//agar i index wale ch ka bit set hai
			//toh character ko include krdlo
         // {get ith bit wala method use krrege..... ek binary no(mask) banao with ith bit 1 and sab 0 ..ab iska given no. ke binary se & krdo if resultant decimal no is zero then bit is 0 and if non zero resultant then it is 1.....yeh mask banjayega 1<<i se   }   
			int mask = (1 << ((n-1)-i));    // (n-1)-i  krna pada as binary no is right se indexed and string is left se indexed ...toh match krne k liye kr na pada......string ka i index is binary no ka (n-1)-i index
			if(num & mask) {
				temp.push_back(ch);
			}
		}
		ans.push_back(temp);
	}

	cout << "printing the subsequences: " << endl;
	for(auto i: ans) {
		cout <<"->"<< i << endl;
	}
}

int main() {

	string str = "abc";
	getSubsequences(str);
	
	return 0;
}

// lc 78
//subsets

//m1 rec
class Solution {
public:
    
    void findSubsequences(vector<int>arr, vector<int>output, int index, vector<vector<int>>& ans) {
	//base case
	if(index >= arr.size() ){
		//ans jo h , vo output vector me build ho chuka h 
		//push krdo
		ans.push_back(output);
		return;
	}

	int no = arr[index];

	// //include
    // //output vector me no ko include krdo
	output.push_back(no);
	findSubsequences(arr, output, index+1, ans);
	// //exclude
	output.pop_back(); // include ke liye push krdia tha voh nikalna pdega // backtrack
	 findSubsequences(arr, output, index+1, ans);
	return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index=0;
        findSubsequences(nums,output,index,ans);
         return ans;
    }
};

//m2 bit masking
class Solution {
public:
vector<vector<int>>  getSubset(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> ans;
	for(int num = 0; num < (1<<n); num++ ) {       
	
		vector<int> temp;
		for(int i=0; i<n; i++) {
			
			int digit = nums[i];
			
			int mask = (1 << ((n-1)-i));                       
			if(num & mask) {
				temp.push_back(digit);
			}
		}
		ans.push_back(temp);
	}
    return ans;
}


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans=getSubset(nums);
        return ans;
    }
};