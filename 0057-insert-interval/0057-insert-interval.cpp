class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& ni) {
        vector<vector<int>>ans;
        bool inserted = false;

        for(auto &curr : nums){

            if(!inserted && ni[0] < curr[0]){
                if(ans.empty() || ans.back()[1] < ni[0]){
                    ans.push_back(ni);
                }
                else
                    ans.back()[1] = max(ans.back()[1] , ni[1]);
                inserted = true;
            }

            if (ans.empty() || ans.back()[1] < curr[0])
                ans.push_back(curr);
            else
                ans.back()[1] = max(ans.back()[1], curr[1]);
        }

        if (!inserted) {
            if (ans.empty() || ans.back()[1] < ni[0])
                ans.push_back(ni);
            else
                ans.back()[1] = max(ans.back()[1], ni[1]);
        }
        return ans;
    }
};