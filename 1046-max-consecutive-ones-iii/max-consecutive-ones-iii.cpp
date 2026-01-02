class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int left  = 0,zeroCount = 0;

        for(int right = 0;right < n ;right++){
            if(nums[right] == 0)zeroCount++;

            while(zeroCount > k){
                if(nums[left] == 0)zeroCount--;
                left++;
            }
            ans = max(ans,right - left+1);
        }
        return ans;
    }
};