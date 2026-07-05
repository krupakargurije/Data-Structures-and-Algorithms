class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int>mp;
        for(int i : nums)mp[i]++;

        return (mp[nums[n/2]] == 1) ? 1 : 0;
    }
};