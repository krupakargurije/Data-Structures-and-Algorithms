class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string>ans;
        if(n == 0) return ans;

        int start = 0;
        for(int i = 1;i<n;i++){
            if(nums[i - 1] + 1 == nums[i])
                continue;

            if(start == i - 1){
                ans.push_back(to_string(nums[start]));
            }
            else{
                string temp = to_string(nums[start]) + "->" +
                              to_string(nums[i - 1]);

                ans.push_back(temp);
            }
            start = i;
        }

        if(start == n - 1) {
            ans.push_back(to_string(nums[start]));
        }
        else {
            ans.push_back(to_string(nums[start]) + "->" +
                          to_string(nums[n - 1]));
        }
        return ans;
    }
};