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