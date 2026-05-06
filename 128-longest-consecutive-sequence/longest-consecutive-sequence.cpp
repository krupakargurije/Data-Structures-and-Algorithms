class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin() , nums.end());

        int ans = 0;
        for(int i : st){
            if(!st.count(i - 1)){
                int currLen = 1;
                int currNum = i;

                while(st.count(currNum + 1)){
                    currLen++;
                    currNum++;
                }
                ans = max(ans , currLen);
            }
        }
        return ans;
    }
};