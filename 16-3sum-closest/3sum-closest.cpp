class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(),nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        
        for(int i = 0;i<n-2;i++){
            int left = i+1;
            int right = n-1;

            while(left < right){
                int currSum = nums[i] + nums[left] + nums[right];

                if(abs(currSum - target) < abs(ans - target)){
                    ans = currSum;
                }

                if(currSum < target)left++;
                else right--;
            }
        }
        return ans;
    }
};