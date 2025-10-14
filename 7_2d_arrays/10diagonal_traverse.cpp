//lc 498

// https://youtu.be/7HAKiGZSrWc?si=g3zZgxXq_-Y0TZ80

//for all points on a right diagonal .. i+j value is contant
//for all points on a left diagonal .. i-j value is contant
//in zero indexed 2d matrix of size n*m ->
//in right diagonals the value ranges as 0,1,2,3...,(n-1)+(m-1) from top left to bottom right
//in left diagonals the value ranges as n-1,n-2,n-3,...,2,1,0,-1,-2...-(m-1) from bottom left to top right


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        map<int, vector<int>> mp;
        
        vector<int> result;
        
        //fill the map using [i+j]
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        
        bool flip = true;
        for(auto &it : mp) {
            if(flip) {
                
                reverse(it.second.begin(), it.second.end());
            }
            
            for(int &num : it.second) {
                result.push_back(num);
            }
            
            flip = !flip;
        }
        
        return result;
    }
};
