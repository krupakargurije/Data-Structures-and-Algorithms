class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;

        for(int i = 0;i<n;i++){
            if(nums[i] > 0)
                ans.push_back(nums[i]);
            else{
                while (!ans.empty() && ans.back() > 0 && ans.back() < abs(nums[i]))ans.pop_back();

                if(!ans.size() || ans.back() < 0)
                    ans.push_back(nums[i]);
                else if(ans.back() == abs(nums[i]))ans.pop_back();
            }
        }
        return ans;
    }
};