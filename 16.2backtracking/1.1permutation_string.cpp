

// all possible permutatiomns of a string

// har ch ko har position par rkhna hai


#include <iostream>
#include<vector>
using namespace std;



// str->  by val chalega 

// void printPermutation(string str, int index) {
// 	//base case
// 	if(index >= str.length() ) {
// 		cout << str << " ";
// 		return;
// 	}

// 	for(int j = index; j<str.length(); j++) {
// 		swap(str[index], str[j]);
// 		//recursion 
// 		printPermutation(str, index+1);
// 	}
//     return;
// }



// str-> by ref , by val  dono  chalega

void printPermutation(string &str, int index) {
	//base case
	if(index >= str.length() ) {
		cout << str << " ";
		return;
	}

	for(int j = index; j<str.length(); j++) {
		swap(str[index], str[j]);
		//recursion 
		printPermutation(str, index+1);
		//backtracking
		swap(str[index], str[j]);
	}
	
    return;
}


int main() {


	string str = "abc";
	int index = 0;
	printPermutation(str, index);
	

	return 0;
}



// note:

// The next_permutation function in C++ is used to transform a given sequence into its next lexicographical permutation. If the function can rearrange the sequence into a lexicographically larger permutation, it does so and returns true. If the sequence is already at its last permutation, the function rearranges it into the first permutation (sorted in ascending order) and returns false.
// The prev_permutation function in C++ is used to generate the previous lexicographical permutation of a sequence. It is essentially the opposite of next_permutation. If the function can rearrange the sequence into a lexicographically smaller permutation, it does so and returns true. If the sequence is already at its first permutation, the function rearranges it into the last permutation (sorted in descending order) and returns false.
// <algorithm> header file
// for doing in [start,end] do next_permutation(pos of starting,position of next to ending) as yeh bhi vhi next_permutation(first pos,last pos) mein krega for [first,last)


// we can use these for getting all permutations 
// note: if we are using next perm...then starting string lexigraphically first wli honi chahie...similarly prev perm men last wali..in order to get all permutations

// eg for "abc" ...we can do

// void permutation(string s){
// 	cout<<s<" ";
// 	while(next_permutation(s.begin(),s.end())){
// 		cout<<s<<" ";
// 	}
// }

//or

// void permutation(string s){
// 	
// do{
//  cout<<s<" ";
// } while(next_permutation(s.begin(),s.end()));






