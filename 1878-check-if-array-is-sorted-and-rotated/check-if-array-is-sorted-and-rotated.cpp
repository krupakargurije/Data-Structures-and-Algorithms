class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int rIdx = -1;

        // Find rotation point (place where order breaks)
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                rIdx = i;
                break;
            }
        }

        // If there is no break → already sorted
        if (rIdx == -1) return true;

        // Check remaining part after rIdx
        for (int i = rIdx + 1; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) return false;
        }

        // Finally check last element with first (circular)
        if (nums[n - 1] > nums[0]) return false;

        return true;
    }
};
