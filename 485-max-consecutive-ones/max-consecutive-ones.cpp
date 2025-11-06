class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0,temp = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i] == 1)temp++;
            else{
                ans = max(ans,temp);
                temp = 0;
            }
        }
        ans = max(ans,temp);
        return ans;
    }
};