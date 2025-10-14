 // next smaller element
 //Given an array.return an array with elements as the Next Smaller Element (NSE) for every element. The NSE for an element x is the first smaller element on the right side of x in the array. Elements for which no smaller element exist (on the right side), consider NSE as -1. 

 // eg for {2,4,6,3,1} -> {1,3,-1,1,-1}



 // bruteforce- har element uthao and uske right m traverse krke check krke ans lagao : nested loops :o(n^2)

 
//better

// #include<iostream>
// #include<stack>
// using namespace std ;

//  vector<int> nextSmaller(int *arr, int n)
// {
//     stack<int> st;
//     vector<int> ans(n);
//     st.push(-1); // -1 for no nse found
//     for (int i = n - 1; i >= 0; i--)
//     {
//         int curr = arr[i];
//         while (st.top()!=-1 && st.top() >= curr)
//         {
//             st.pop();
//         }
//         ans[i]=st.top();
//         st.push(curr);
//     }
//     return ans;
// }     // tc o(n)


// int main()
// {
//     int arr[5] = {8, 4, 6, 2, 3};
//     int n = 5;
//     vector<int> ans = nextSmaller(arr, n);
   
//     for (auto i : ans)
//     {
//         cout << i << " ";
//     }

//     return 0;

// }


// next smaller element index

#include<iostream>
#include<stack>
using namespace std ;

 vector<int> nextSmaller(int *arr, int n)
{
    stack<int> st;
    vector<int> ans(n);
    st.push(-1); //-1 for no nsi found
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top()!=-1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}     // tc o(n)


int main()
{
    int arr[5] = {8, 4, 6, 2, 3};
    int n = 5;
    vector<int> ans = nextSmaller(arr, n);
   
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;

}


// note: yeh -1 bina stack m push kre bhi kr skte

 // next smaller element
 vector<int> nextSmaller(int *arr, int n)
{
    stack<int> st;
    vector<int> ans(n);
    
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (!st.empty()&& st.top() >= curr)
        {
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(curr);
    }
    return ans;
} 