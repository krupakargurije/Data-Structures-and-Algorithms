class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int left = 0, sum = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum > k) {
                sum -= nums[left];
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
