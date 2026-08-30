class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxPos = 0 , minPos = 0;

        for(int i = 1;i<n;i++){
            if(nums[i] > nums[maxPos])
                maxPos = i;
            if(nums[i] < nums[minPos])
                minPos = i;
        }

         int deleteLeft = max(maxPos, minPos) + 1;

        // Both removed from the right
        int deleteRight = max(n - maxPos, n - minPos);

        // One removed from each side
        int deleteBoth =
            min(maxPos + 1, n - maxPos) +
            min(minPos + 1, n - minPos);

        return min({deleteLeft, deleteRight, deleteBoth});
    }
};