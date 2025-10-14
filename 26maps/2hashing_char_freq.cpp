// striver

// given string ...tell frequency of particular character

// method-hashing

//using hash array
#include<iostream>          
using namespace std ;
int main()
{string s="yashgoyal";

//pre compute

// //m1(works in all cases) - hashindex of character is equal to character ki ascii value   then uss index par count maintain krlo  // we have total 256 characters having ascii value - 0 to 255
// int hash[256]={0};  //256 characters    // size - 256 and indexes - 0 to 255 created
// for(int i = 0;i<s.size();i++) {
// hash[s[i]]++;      // here s[i] is char but uska implicit conversion hojayegi to int (ascii value) (as int is expected in [])  and fir voh  dekhi jaayegi
// }

//m2 (works when string only contains particaular type of characters whose ascii value are in order)...(like here given only small letters ie a,b,c....z ..inki ascii values are in line ...65,66,67.... ese) - here we can take hashindex for 'a'  to be 0 ,'b' ka 1 , 'c' ka 2 ......... , 'z' ka 25 ...so we dont need to create 256 size ...and here only 26 size will be required ;)
int hash[26]={0};      // 26 letters hai // size-26 , indexes -0 to 25 created
for(int i = 0;i<s.size();i++) {
hash[s[i] - 'a']++;   // first wala minus krlo sabse  // char-char : both implicitly converted to int (their ascii value) fir operation and result is int // 'a'-'a'= 65-65=0, 'b'-'a'=66-65=1,........  'a' ka 0 leliya , 'b' ka 1 so on
}



// fetch
char c;
cin >> c;
// cout << hash[c] << endl;
cout << hash[c-'a'] << endl;  
return 0;
}

// note agar a ka 1 se b ka 2 se c ka 3  krna hooo toh ..... s[i] -'a'+1 krdoooooo

// note:
// int array can be made till 10^6 only (inside main) (globally -10^7) ...for large than that we cant make...so we cant use hashing by array in that case......soln is using maps for hashing