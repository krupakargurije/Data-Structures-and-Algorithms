class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        // Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    
    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
        return mat == target;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < 4; i++) {
            if(isEqual(mat, target)) return true;
            rotate(mat);
        }
        return false;
    }
};