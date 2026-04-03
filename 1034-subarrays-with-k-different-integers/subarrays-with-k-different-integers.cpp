class Solution {
    private:
    int helper(vector<int>& nums, int k){
        if (k < 0) return 0;
        int n = nums.size();
        unordered_map<int , int>mp;
        int left = 0 , ans = 0;

        for(int right = 0;right < n ;right++){
            mp[nums[right]]++;

            while(mp.size() > k){
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums , k) - helper(nums , k - 1);
    }
};