// Maximize The Cut Segments
//  gfg - https://www.geeksforgeeks.org/problems/cutted-segments1642/1

// method- exploring all possible ways

// class Solution
// {
// public:
//     int maximizeTheCuts(int n, int x, int y, int z)
//     {
//         if (n == 0)
//         {
//             return 0;
//         }
//         if (n < 0)
//             return INT_MIN;  // invalid case .... max lena h isliye int_min dediya isko

//         // maine x len ka 1 segement cut krlia and baaaki recursion dekhlega
//         int option1 = 1 + maximizeTheCuts(n - x, x, y, z);
//         // maine y len ka 1 segement cut krlia and baaaki recursion dekhlega
//         int option2 = 1 + maximizeTheCuts(n - y, x, y, z);
//         // maine z len ka 1 segement cut krlia and baaaki recursion dekhlega
//         int option3 = 1 + maximizeTheCuts(n - z, x, y, z);
        
//         int finalAns = max(option1, max(option2, option3));
//         return finalAns;
//     }
// };                               

// TLE dega as dp use krni pdegi