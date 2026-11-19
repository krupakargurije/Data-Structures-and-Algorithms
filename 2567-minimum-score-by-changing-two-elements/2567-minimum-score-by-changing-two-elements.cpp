class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min({nums[n-1] - nums[2], nums[n-3] - nums[0], nums[n-2] - nums[1]});
    }
};

// 1,4,7,8,5

// min diff = 8 - 7 = 1
// max diff = 8 - 1 = 7

// score = 7 + 1 = 8

// 6,10,7,8,5

//5 6 7 8 10

// max = 10 - 5 = 5
// min = 6 - 5 = 1 -> 6 - 6 = 0

//6 6 7 8 10

//max = 10 - 7 = 3

//score = 3 + 0
