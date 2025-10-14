
// (a+(b))  :  b wali are redundant brackets

// given valid parentheses .check redundant brackets present or not

// logic - opening closing bracket ke bich >0 operators hone chahie

#include <iostream>
#include <stack>
using namespace std;

bool checkRedundant(string &str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            int operatorCount = 0;
            while (st.top() != '(')
            { // idhar top use karliya bina stack empty ,not empty dekhe as given hai valid parentheses hai so closing se phle toh opening toh aaya hi hogaaa so empty toh nhi hi hai
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    operatorCount++;
                }
                // top pop krdo 
                st.pop();
            }

            // yha pr aap tabhi pohochgye  aapke stack k top pr ek opening bracket hai ab

            st.pop(); // hatado usse no need ab uski

            // now check operator count
            if (operatorCount == 0)
            {
                return true; // redundant present
            }
    
        }
        // yaha pahuche mtlb abhi tak redundant nhi mila aage bhadhoo
    }
    // agar main yha tk pohohcha hu iska matlab k har ek bracket k pair k beech mein atleast ek operator pkka mila hoga
    return false;
}

int main()
{

    string str = "((a+b)*(c+(d)))";

    bool ans = checkRedundant(str);

    if (ans == true)
    {
        cout << "Redundant Brackets Present" << endl;
    }
    else
    {
        cout << "Redundant Brackets Not Present" << endl;
    }
    return 0;
}