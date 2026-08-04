class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int start = nums[0] , end = nums[n-1];

        vector<int>ans;
        int pos = 0;

        for(int i = start;i<=end;i++){
            while(pos < n && nums[pos] != i){
                ans.push_back(i);
                i++;
            }
            pos++;
        }
        return ans;
    }
};