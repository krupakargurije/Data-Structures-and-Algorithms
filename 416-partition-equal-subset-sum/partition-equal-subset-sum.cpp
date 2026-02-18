class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i : nums)totalSum += i;

        int tar = totalSum /2;
        if(totalSum % 2 != 0)return false;

        vector<bool> curr(tar + 1, false) , prev(tar + 1, false);
        prev[0] = true;

        if(nums[0] <= tar)
            prev[nums[0]] = true;

        for(int idx = 1;idx<n;idx++){
            for(int target = 1;target <= tar;target++){
                bool nonPic = prev[target];

                bool pic = false;
                if(nums[idx] <= target)
                    pic = prev[target - nums[idx]];
                    
                curr[target] = pic || nonPic;
            }
            prev = curr;
        }
        return prev[tar];
    }
};