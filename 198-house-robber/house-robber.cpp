class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        int prev = nums[0];
        int curr = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int temp = max(curr, nums[i] + prev);
            prev = curr;
            curr = temp;
        }
        return curr;        
    }
};