class Solution {
    vector<int>delRow = {-1 , 0 , 1 , 0};
    vector<int>delCol = {0 , 1 , 0 , -1};
    
    private:
    void helper(vector<vector<int>>& arr , vector<vector<int>>& tower ,
    vector<vector<int>>& vis , int r , int c){
        int n = arr.size();
        int m = arr[0].size();
        
        tower[r][c] = 1;
        vis[r][c] = 1;
        
        for(int i = 0;i<4;i++){
            int row = r + delRow[i];
            int col = c + delCol[i];
            
            if(row >= 0 && row < n && col >= 0 && col < m 
            && !vis[row][col] && arr[row][col] >= arr[r][c]){
                helper(arr , tower , vis , row , col);
            }
        }
    }
  public:
    int countCoordinates(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        vector<vector<int>>p(n , vector<int>(m , 0)) , q(n , vector<int>(m , 0));
        vector<vector<int>>pVis(n , vector<int>(m , 0)) , qVis(n , vector<int>(m , 0));
        
        // first col
        for(int i = 0;i<n;i++){
            helper(arr , p , pVis , i , 0);
        }
        
        // first row
        for(int j = 0;j<m;j++){
            helper(arr , p , pVis , 0 , j);
        }
        
        // last col
        for(int i = 0;i<n;i++){
            helper(arr , q , qVis , i , m - 1);
        }
        
        // last row
        for(int j = 0;j<m;j++){
            helper(arr , q , qVis , n - 1 , j);
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0 ; j<m;j++){
                if(p[i][j] && q[i][j])ans++;
            }
        }
        return ans;
    }
};







