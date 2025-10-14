// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
// Given two integers x and y, return the Hamming distance between them.

// Example :

// Input: x = 1, y = 4
// Output: 2
// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
// The above arrows point to positions where the corresponding bits are different.



// Approach    (note: xor of bits  0^0 , 1^1  is bit 0 and 1^0 is bit 1) (xor of same gives zero and xor of diff gives 1)
// XOR Operation: Compute x XOR y to get a number where bits are set to 1 where bits differ in x and y
// Counting Set Bits: Use a loop to count how many bits are set to 1 in the result of the XOR operation. This count gives the Hamming distance.

    
// class Solution {
// public:
//     int hammingDistance(int x, int y) {
//         int count =0 ; 
//         int result = x ^ y;
//         //Now counting the number of ones in the result;
//         while(result > 0 ){
//             if((result & 1 )==1){
//                 count ++;
//             }
//             result = result>>1;
//         }
//         return count ;
//     }
// };



// lc 2220

// no of different bits dekhni

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n=start^goal;
        int count=0;
        while(n>0){
         n=n&(n-1);
            count++;
}
        return count;
    }
};

