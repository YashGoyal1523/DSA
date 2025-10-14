// gfg par h
//https://www.geeksforgeeks.org/problems/first-repeating-element4018/1


// first repeating element

// Given an array arr[], find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.
// Note:- The position you return should be according to 1-based indexing. 

// method 1 : bruteforce : nested loops: o(n^2): starting se ek ek element uthao uske liye baaki array m check kro dobara present h ya nhi voh ....phla element jiske liye dobara miljaye ...uska index return krdo .....pure mein agar kisika ni mila toh -1 return   // tle dega

// method 2 : hashing 
// phle saare array m traverse krke sabka count nikall lo ek map mein
// ab array m firse start se traverse shuru kro and element ka count map mein dekhte jao ..phla element jiska >1 mil jaaye uska index return krdo......pure m kisi ka nhi mila toh -1 return
// tc o(n)  sc o(n)

// class Solution {
// public:
// int firstRepeated(vector<int> &arr) {
// int n=arr.size();
// unordered_map<int, int>hash;
// for(int i=0;i<n;i++){
// hash [arr[i]]++;
// }
// for(int i=0;i<n;i++){
// if(hash [arr[i]] > 1){
// return i+1;
// }
// }
// return -1;
// }
// };