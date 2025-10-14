
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