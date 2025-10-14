// previous smaller element
//  //Given an array.return an array with elements as the Next previous Element (NpE) for every element. The NSE for an element x is the first smaller element on the left side of x in the array. Elements for which no smaller element exist (on the right side), consider NSE as -1. 


// bruteforce: nested loops : har ke liye left m dekho

// better

// #include<iostream>
// #include<stack>
// using namespace std ;

//  vector<int> prevSmaller(int arr[], int n)
//     {
//         stack<int> st;
//         vector<int> ans(n);
//         st.push(-1); //-1 for no pse found
//         for (int i = 0; i < n; i++)
//         {
//             int curr = arr[i];
//             while (st.top()!=-1&&st.top() >= curr)
//             {
//                 st.pop();
//             }

//             ans[i]=st.top();
//             st.push(curr);
//         }
//         return ans;
//     }


    
// int main()
// {
//     int arr[5] = {8, 4, 6, 2, 3};
//     int n = 5;
   
//     vector<int> ans = prevSmaller(arr, n);

//     for (auto i : ans)
//     {
//         cout << i << " ";
//     }

//     return 0;

// }



// prev smaller element index


#include<iostream>
#include<stack>
using namespace std ;

 vector<int> prevSmaller(int arr[], int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1); //-1 for no psi found
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (st.top()!=-1&&arr[st.top()] >= curr)
            {
                st.pop();
            }

            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }


    
int main()
{
    int arr[5] = {8, 4, 6, 2, 3};
    int n = 5;
   
    vector<int> ans = prevSmaller(arr, n);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;

}