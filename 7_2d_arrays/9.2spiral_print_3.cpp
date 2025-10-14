// lc 885 spiral matrix 3

// https://youtu.be/dt0UzAz7SPg?si=3vo29Loa7RPoew-C

// jab bhi east ya west m jaate toh steps ek increase hojata



// class Solution
// {
// public:
//     vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
//     {
//         vector<vector<int>> directions = {
//             {0, 1},  // EAST
//             {1, 0},  // SOUTH
//             {0, -1}, // WEST
//             {-1, 0}  // NORTH
//         };
//         vector<vector<int>> result;
//         int steps = 0; // how much steps to take
//         int dir = 0;   // in dir direction
//         result.push_back({rStart, cStart});
//         int currX=rStart;
//         int currY=cStart;
//         int newX;
//         int newY;
//         while (result.size() < rows * cols)
//         {
//             if (dir == 0 || dir == 2)
//             { // 0 = EAST, 2 = WEST
//                 steps++;
//             }
//             for (int count = 0; count < steps; count++)
//             {
//                 newX = currX+ directions[dir][0];
//                 newY = currY+ directions[dir][1];
//                 if (newX>= 0 && newX< rows && newY >= 0 && newY< cols)
//                 { // Valid cell
//                     result.push_back({newX, newY});
//                 }
//                 currX=newX;
//                 currY=newY;
//             }
//             dir = (dir + 1) % 4;
            
        
//         }
//         return result;
//     }
// };