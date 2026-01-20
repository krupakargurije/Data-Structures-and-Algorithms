class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos,neg;

        for(int i : nums){
            if(i > 0)pos.push_back(i);
            else neg.push_back(i);
        }

        vector<int>ans;
        for(int i = 0;i<pos.size();i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }

        return ans;
    }
};