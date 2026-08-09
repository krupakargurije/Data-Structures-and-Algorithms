class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mxIdx = 0;

        for(int i = 0;i<n;i++){
            if(i > mxIdx)return false;
            if(mxIdx >= n-1)return true;
            mxIdx = max(mxIdx , nums[i] + i);
        }
        return mxIdx >= n-1;
    }
};