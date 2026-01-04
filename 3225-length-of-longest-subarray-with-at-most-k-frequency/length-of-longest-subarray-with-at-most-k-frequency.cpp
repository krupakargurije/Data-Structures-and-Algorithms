class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0]++;
        int left = 0,ans = INT_MIN;

        for(int right = 0;right < n;right++){
            mp[nums[right]]++;

            while(mp[nums[right]] > k){
                mp[nums[left]]--;
                left++;
            }

            ans = max(ans,right - left + 1);
        }
        return ans;
    }
};