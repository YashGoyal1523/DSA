// lc 205

//we will normalise both s and t into a similar format and then compare them
//string ke phle distinct character ko a , dusre ko b , teesre ko c and so on ese ese sabko  leke modify krlege dono ko .... same bangye toh true else false



// class Solution {
// public:

//     void modifyToSameFormat(string&a){
//         // mapping characters
//         unordered_map<char,char>m;
//         char value='a';
//         for(int i=0;i<a.size();i++){
//             if(m[a[i]]==0) {  // already mapped h toh aage bhadna and nhi h toh banao
//                 m[a[i]]=value;
//                 value++;
//             }
//         }
//         //updating string
//         for(int i=0;i<a.size();i++){
//             a[i]=m[a[i]];
//         }

//     }


//     bool isIsomorphic(string s, string t) {
//         modifyToSameFormat(s);
//         modifyToSameFormat(t);
//         return s==t;
//     }
// };