class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int t) {
        int n = nums.size();
        int m = nums[0].size();

        for(int i = 0;i<n;i++){
            if(t < nums[i][0] || t > nums[i][m-1])
                continue;
            
            int left = 0 , right = m-1;
            while(left <= right){
                int mid = left + (right - left) / 2;

                if(nums[i][mid] == t)
                    return true;
                else if(t < nums[i][mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};