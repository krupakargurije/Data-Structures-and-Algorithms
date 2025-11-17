class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        
        while (i < n && nums[i] != 1) {
            i++;
        }

        if (i == n) return true;
        int temp = 0;
        
        for (i = i + 1; i < n; i++) {
            if (nums[i] == 1) {
                if (temp < k) return false;
                temp = 0;
            } else {
                temp++;
            }
        }

        return true;
    }
};
