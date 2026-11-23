class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        bool isInserted = false;
        vector<vector<int>>ans;


        for(auto it : intervals){
            
            if(!isInserted && ni[0] < it[0]){
                if(ans.empty() || ans.back()[1] < ni[0]){
                    ans.push_back(ni);
                }
                else
                    ans.back()[1] = max(ans.back()[1] , ni[1]);
                isInserted = true;
            }

            if(ans.empty() || ans.back()[1] < it[0]){
                ans.push_back(it);
            }
            else{
                ans.back()[1] = max(ans.back()[1] , it[1]);
            }
        }

        if (!isInserted) {
            if (ans.empty() || ans.back()[1] < ni[0])
                ans.push_back(ni);
            else
                ans.back()[1] = max(ans.back()[1], ni[1]);
        }
        return ans;
    }
};