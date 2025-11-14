class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> nums(n,vector<int>(n,0));

        for(auto it : queries){
            int row1 = it[0];
            int col1 = it[1];
            int row2 = it[2];
            int col2 = it[3];

            for(int i = row1;i<=row2;i++){
                for(int j = col1;j<= col2;j++){
                    nums[i][j]++;
                }
            }
        }
        return nums;
    }
};