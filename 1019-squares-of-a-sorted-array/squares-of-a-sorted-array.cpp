class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>mp;
        for(int i : nums){
            mp.push(i * i);
        }

        vector<int> ans;
        while(!mp.empty()){
            ans.push_back(mp.top());
            mp.pop();
        }
        return ans;
    }
};