// note :  string str,int x  and we do str.push_back(x) -> toh iss case mein kya hoga since push_back here was expecting a char toh phle implicit conversion of x to its char hoga(acc to ascii) and fir voh char push hoga

// note: suppose we have a string s and we do s.push_back(char+int) toh isme aise processing hogi....phle implicit typeconversion of char to int (ascii) fir unka addition and resultant int. ab push_back was expecting a char as its a string toh result ka implicit conversion to char (acc to ascii) and fir voh push hoga





// we need to insert given int datatype in  string 

// for single digit integers
// hum x(int) ko 'x'(char) banake daalege : x- single digit integer
// we can use push_back with the int + '0' approach to append the integer as a character to a string.
// This works because the character '0' in ASCII has a value of 48, so adding an integer between 0 and 9 to '0' will result in the ASCII value of the corresponding digit character. 

// eg

// string s="";
// int x=8;
// s.push_back(x+'0');  // adds  '8' (char) to s


// This approach works only for single-digit integers (0-9) (ascii : 48-57).

/// For multi-digit integers,
// you'll need to convert the entire integer to a string and then append it 
// you can use to_string() to convert into string



#include <iostream>
#include <string>
using namespace std;


int main() {
    string s = "The number is ";
    int i = 5;
    
    // Convert integer to corresponding character and push back to string
    s.push_back(i + '0'); 
    cout << s << endl;  // Output: "The number is 5"
    return 0;
}



// note: 
//similarly
// to push single digit given in char datatype into int vector
// we will convert 'x' (char) to x (int) : x - single digit integer
// we do char - '0'
// vector<int>v1;
// char x='7';
// v1.push_back(x -'0');  // will add  7 (int) to v


// lc 2678

// class Solution {
// public:
//     int countSeniors(vector<string>& details) {
//          int count=0;
//         for(auto i: details){
//            int age=10*(i[11]-'0') + (i[12]-'0');
//             if(age>60) count ++;
//         }
//         return count;
//     }
// };