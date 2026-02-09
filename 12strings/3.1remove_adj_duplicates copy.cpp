// lc 1047 . Remove All Adjacent Duplicates In String

//m1: using string

// ek ans string banao 
// s mein traverse kro and iske curr char ko ans ke last char se compare kro
// if ans is empty then char daaldo
// if ans ka last char is diff from s ka curr char then ans m daaldo curr char and aage bhado s mein
// if ans ka last char is same to s ka curr char then ans ka last char hatado and aage bhado s mein 
// kro till s traverse hojaye
// ans return



// class Solution {
// public:
//     string removeDuplicates(string s) {
//         string ans;  // new string banake usme daalege ans

//     int i=0; // s mein traverse krne ke liye

//     while (i<s.length()) 
//     {   // when s ka current characeter and ans ka rightmost character is same   
//         if (ans.length()>0 && ans[ans.length()-1]==s[i])            // >0 wali lagani padi as jab length zero hogi toh length-1 index negative banjagyegi and error show.... 
//         {
//             ans.pop_back();    // toh ans ka rightmost udana pdega
//         }
//         else {
//         ans.push_back(s[i]);  // length is zero or same nhi h toh ... daaldo s se ans mein
//         }
//     i++;
//     }
//     return ans;

//     }
// };
// // for loop bhi use kr skte


// m2 : using stack

// ek stack banao st of type char
// s mein traverse kro and iske curr char ko st ke top char se compare kro
// if st is empty then char daaldo
// if st ka top char is diff from s ka curr char then st m daaldo curr char and aage bhado s mein
// if st ka top char is same to s ka curr char then st ka top char hatado and aage bhado s mein
// kro till s traverse hojaye 
// string ans banao
// st ke uper se elements ans m daalte jao
// ans reverse kro
// return ans


// class Solution {
// public:
//     string removeDuplicates(string s) {
//         stack<char>st;
//         for(int i=0;i<s.size();i++){
//             char ch=s[i];
//             if(!st.empty()&&st.top()==ch){  //  empty wali condition daalni padi as top access krre toh empty nhi hona chahie.....
//                 st.pop();
                
//             }
//             else{  // st is empty or character mismatch
//                 st.push(ch);
//             }
//         }

//         string ans="";
//         while(!st.empty()){
//             char ch=st.top();
//             ans.push_back(ch); //ans+=ch;
//             st.pop();
//         }

//         reverse(ans.begin(),ans.end());

//         return ans;
//     }
// };



