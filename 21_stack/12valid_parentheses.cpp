// // leetcode 20


// // method - string mein traverse karte rho agar opening bracket mile toh stack mein push krte jao and if closing bracket mile toh and agar  empty stack hai and if empty nhi h then usi ka opening nhi h  top par then return invalid else  agar usi ka opening pada hai toh pop krdo top and aage bhadoo.... ese ese last mein string khatm hone  par agar sab pop hogye and empty hogya stack toh return valid



// class Solution
// {
// public:
//     bool isValid(string s)
//     {
//         stack<char> st;
//         for (int i = 0; i < s.length(); i++)
//         {
//             char ch = s[i];

//             if (ch == '(' || ch == '[' || ch == '{')
//             {
//                 // open bracket mila-> just push
//                 st.push(ch);
//             }

//             else
//             {
//                 // closing bracket mila

//                 if (!st.empty())
//                 { // stack empty noi     // condition daalni pdegi as agar empty hui and top access krra toh error aayega

//                     if (ch == ')' && st.top() == '(')
//                     {
//                         st.pop();
//                     }
//                     else if (ch == '}' && st.top() == '{')
//                     {
//                         st.pop();
//                     }
//                     else if (ch == ']' && st.top() == '[')
//                     {
//                         st.pop();
//                     }
//                     else
//                     {
//                         // no match
//                         return false;
//                     }
//                 }

//                 else
//                 {
//                     // stack is empty 
//                     return false;
//                 }
//             }
//         }

//         // string over now check stack

//         if (st.size() == 0)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//  };