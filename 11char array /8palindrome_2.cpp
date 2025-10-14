//leetcode 125

// m1

// class Solution {
// public:
//     bool isPalindrome(string s) {
//       // convert to upper case
//         int i=0;
//         while(s[i]!='\0'){
//             if(s[i]>='A'&&s[i]<='Z'){
//                 s[i]=s[i]-'A'+'a';
//             }
//             i++;
//         }

//         // ab alphanumeric ko starting mein lagado

//           int j=0;
//         // note: now i is also determining size
//         for(int x=0;x<i;x++){
//             if((s[x]>='a'&&s[x]<='z')||(s[x]>='0'&&s[x]<='9')){
//                 s[j]=s[x];
//                 j++;
//             }
//         }

//         // check palindrome in shuru ke alphanumeric elements
//         int a=0;
//         int b=j-1;  // j is on next index of last alphanumeric
//         int flag=1;
//         while(a<b){
//             if(s[a]!=s[b]){
//                 flag=0;
//                 break;
//             }
//             else{
//                 a++;
//                 b--;
//             }
//         }
//         if(flag==1){
//             return true;
//         }
//         else {
//             return false;
//         }
//     }
// };

//m2

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         // traverse krte jao and agar lowercase ya no mile toh nyi string m daalte jao and upper case mile toh uske lower krke daaldo baakio ko ignore...fir new string m check krlo..
//      vector<char>ans;
//      int i=0;
     
//      while(s[i]!='\0'){
//         if(s[i]>='A'&&s[i]<='Z'){
//             s[i]=s[i]-'A'+'a';
//             ans.push_back(s[i]);
//             i++;
            
//         }
//         else if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
//             ans.push_back(s[i]);
//             i++;
//         }
//         else i++;
//      }
//     int a=0;
//     int b=ans.size()-1; // j will be on next index of last character in ans string
//     int flag=0;
//     while(a<b){
//         if(ans[a]!=ans[b]){
//             flag=1;
//             break;
//         }
//         else{
//             a++;
//             b--;
//         }
//     }
//     if(flag==0){
//         return true;
//     }
//     else return false;
//     }
// };
