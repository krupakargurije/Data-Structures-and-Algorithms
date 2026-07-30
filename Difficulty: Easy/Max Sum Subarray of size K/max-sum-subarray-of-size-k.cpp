class Solution {
  public:
    int maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0 , curr = 0;
        int left = 0;
        
        for(int right = 0;right<n;right++){
            curr += nums[right];
            
            while(right - left + 1 > k){
                curr -= nums[left];
                left++;
            }
            ans = max(ans , curr);
        }
        return ans;
    }
};