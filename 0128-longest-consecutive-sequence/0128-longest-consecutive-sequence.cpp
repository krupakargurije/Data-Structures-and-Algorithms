class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin() , nums.end());

        int ans = 0;
        for(int i : st){
            if(!st.count(i - 1)){
                int curr = 0;
                int temp = i;
                while(st.count(temp)){
                    curr++;
                    temp++;
                }
                ans = max(ans , curr);
            }
        }
        return ans;
    }
};