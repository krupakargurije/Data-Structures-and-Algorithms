class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int left = 0;
        int curSum = 0;

        for (int right = 0; right < nums.size(); right++) {
            curSum += nums[right];

            while (curSum >= target) {
                minLen = min(minLen , right - left + 1);
                curSum -= nums[left++];
            }
        }
        return minLen != INT_MAX ? minLen : 0; 
    }
};