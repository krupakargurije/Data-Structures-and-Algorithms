class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        int leftMax = nums[0];
        int ans = INT_MIN;

        for (int j = k; j < n; j++) {
            leftMax = max(leftMax, nums[j - k]);
            ans = max(ans, leftMax + nums[j]);
        }

        return ans;
    }
};