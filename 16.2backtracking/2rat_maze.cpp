// given 2d matrix
// given src box , dest box
// box value-0/1
// 0 -> no path 1 ->path
// can move up down left right
// print all possible paths

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int srcx, int srcy, int newx, int newy, int maze[][4], int row, int col, vector<vector<bool> > &visited)
{   // path close na ho and out of bound na ho and already visited na ho(vrna infinte loop m fasjayege) toh safe h uspe jaana vrna noi
    if ( (newx >= 0 && newx < row) && (newy >= 0 && newy < col) && maze[newx][newy] == 1 && visited[newx][newy] == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, int destx,int desty,string &output, vector<vector<bool> > &visited)
{

    // base case
    
    if (srcx == destx && srcy == desty)
    {
        // reached destination
        cout << output << endl;
        return;
    }

    // 1 case solve karo and baakai recursion sambhal lega

    // UP
    int newx = srcx - 1;
    int newy = srcy;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('U');
        printAllPath(maze, row, col, newx, newy,destx,desty, output, visited);
        // backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }

    // RIGHT
    newx = srcx;
    newy = srcy + 1;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('R');
        printAllPath(maze, row, col, newx, newy,destx,desty, output, visited);
        // backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }

    // DOWN
    newx = srcx + 1;
    newy = srcy;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('D');
        printAllPath(maze, row, col, newx, newy,destx,desty, output, visited);
        // backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }

    // LEFT
    newx = srcx;
    newy = srcy - 1;
    if (isSafe(srcx, srcy, newx, newy, maze, row, col, visited))
    {
        // mark visited
        visited[newx][newy] = true;
        // call recursion
        output.push_back('L');
        printAllPath(maze, row, col, newx, newy,destx,desty, output, visited);
        // backtracking
        output.pop_back();
        visited[newx][newy] = false;
    }
}

int main()
{

    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1}};
    int row = 4;
    int col = 4;

    int srcx = 0;
    int srcy = 0;
    int destx=row-1;
    int desty=col-1;

    string output = "";

    // create visited 2D ARRAY
    vector<vector<bool> > visited(row, vector<bool>(col, false));

    if (maze[srcx][srcy] == 0 || maze[destx][desty] == 0)
    {
        // src/dest position is Closed, that means RAT cannot move/reach
        cout << "No Path Exists" << endl;
    }
    else
    {
        visited[srcx][srcy] = true;
        printAllPath(maze, row, col, srcx, srcy,destx,desty, output, visited);
    }


    
    return 0;
}