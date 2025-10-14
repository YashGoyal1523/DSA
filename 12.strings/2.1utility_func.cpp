#include<iostream>
#include<string>  
using namespace std ;
int main()
{ string str="hello";

// length finding using length() func....returns value of length
int length=str.length();
cout<<length<<endl;

string s;
string ss="";
cout<<s.length()<<endl<<ss.length()<<endl;

// reverse string
reverse(str.begin(),str.end());
cout<<str<<endl;

// checking empty or not using empty() func...returns true if yes ..false if not
bool empty=str.empty();
cout<<empty<<endl;
//  accessing index..... str[index] or str.at(index).....
char at0=str[0]; 
cout<<str.at(0)<<endl<<str[0]<<endl;

// character at front  
char fro=str.front();
cout<<str.front()<<endl;
// character at back
cout<<str.back()<<endl;
// append() func :str1 mein str2 add krna  str1.append(str2).....
string strr="world";
str.append(strr);
cout<<str<<endl;
// erase a part of string using erase() func ...erase(index jaha se shuru hona,kitne characters krne remove)  ....note remaining right wale characters leftwards adjust hojate and extra index delete hojate
str.erase(2,2);
cout<<str<<endl;
// inserting a string in another.....insert() func.....insert(index jaha se add krna,string jo add krna)
str.insert(4,"hello");
str.insert(4,strr);
// to add a character at end
str.push_back('a');
// to remove character from end
str.pop_back();

// to find a string in another string...using find() func......str1.find(str2)....str1 mein str2 dhundhre......The function returns the index of the first character of the sub-string.If occurs more than one than returns for first occurrence.If the sub-string is not found it returns string::npos
string str1="i am yash";
string str2="am";

if (str1.find(str2,1)==string::npos)        
{
    cout<<"not found";
}
else //str1.find(str2)!=string::npos
cout<< "found with starting index : "<<str1.find(str2) <<endl;  // to get starting index....... 

//note str.find(s,pos) - finds string s from index pos....if pos is omitted it starts from starting


// compare two string.... str1.compare(str2) ....str1 se compare krre str2.......cant be compared as if(str1==str2)....character kar skte aisee normal
// if returns
// 0	They compare equal
// not 0 then not equal
//<0	Either the value of the first character that does not match is lower in the compared string  (str2), or all compared characters match but the compared string is shorter.
//>0	Either the value of the first character that does not match is greater in the compared string, or all compared characters match but the compared string is longer.
 
// upper lower case bhi match hota



// to take out a substring from string :   substr(index jaha se shuru hona,length jitni bahar nikalni)

cout<<str1.substr(2,3);
// note: if length not mentioned then end tak lejayega ....  str1.substr(2)

return 0;
}  




// more functions can be seen on cppreference or cplusplus


// to reverse a string we can use reverse() func

// sort() fn in string : sorts lexicographically (phle first character ke acc , voh same fir second ke acc, so on) (eg increasing orders - "a","b","c" ; "ab" ,"ac" ; "a","ab"    eg decreasing order - "c","b","a" ; "ab","ac" ; "ab","a"   eg decreasing order - "9","11" ; "12","1"  )



// note: isdigit(ch) : to check if a char ch is a digit (0-9) or not : returns true or false