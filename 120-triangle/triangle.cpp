class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size();
        for(int i = n-2;i >= 0;i--){
            for(int j = 0;j<nums[i].size();j++){
                int below = nums[i+1][j];
                int Bright = nums[i+1][j+1];
                nums[i][j] += min(below,Bright);
            }
        }
        return nums[0][0];
    }
};
