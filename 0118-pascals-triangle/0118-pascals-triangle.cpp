class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});

        for(int i = 1;i<numRows;i++){
            vector<int>curr;
            const auto &prev = ans[i-1];

            curr.push_back(1);

            for(int k = 1;k<prev.size();k++){
                int currNum = 0;

                currNum += prev[k - 1];
                currNum += prev[k];
                curr.push_back(currNum);
            }
            curr.push_back(1);
            ans.push_back(curr);
        }
        return ans;
    }
};