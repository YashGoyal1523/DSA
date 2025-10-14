// lc 72 edit distance

// approach :

// char match :
//        -> 0+rec(i+1,j+1)
// char not match :
// replace -> 1+rec(i+1,j+1)
// insert -> 1+rec(i,j+1)
// delete -> 1+rec(i+1,j)   

// class Solution
// {
// public:
//     int solve(string &a, &string b, int i, int j)    // mle aara tha isiliye by ref krdi string
//     {
//         // base case
//         if (i == a.length())
//         { // agar a khatm hogya toh b ke jitne bach gye utne add krne dege a mein toh utne hi add hojayege no of operation mein
//             return b.length() - j;
//         }
//         if (j == b.length())
//         { // agar b khatm hogya toh a ke jitne bach gye utne remove krne pdege a mein toh utne hi add hojayege no of operation mein
//             return a.length() - i;
//         }

//         int ans = 0;
//         if (a[i] == b[j]) // match
//         {   // koi operatio nhi chahie
//             ans = 0 + solve(a, b, i + 1, j + 1);
//         }
//         else // no match
//         {    // operation kro
//              //  replace
//             int replace = 1 + solve(a, b, i + 1, j + 1);
//             //  insert
//             int insert = 1 + solve(a, b, i, j + 1);
//             //  remove
//             int remove = 1 + solve(a, b, i + 1, j);
//             ans = min(insert, min(remove, replace));
//         }
//         return ans;
//     }
//     int minDistance(string word1, string word2)
//     {
//         int i = 0;
//         int j = 0;
//         int ans = solve(word1, word2, i, j);
//         return ans;
//     }
// };


// tle dega dp lagani pdegi