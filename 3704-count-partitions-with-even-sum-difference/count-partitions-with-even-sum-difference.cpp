class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int leftSum = nums[0],rightSum = 0;
        int ans = 0,n = nums.size();
        for(int i : nums)rightSum += i;
        rightSum -= nums[0];
        
        for(int i = 1;i<n;i++){
            leftSum += nums[i];
            rightSum -= nums[i];
            int diff = leftSum - rightSum;
            if(diff % 2 == 0)ans++;
        }
        return ans;
    }
};