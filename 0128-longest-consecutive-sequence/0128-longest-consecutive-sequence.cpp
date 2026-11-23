class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st(nums.begin() , nums.end());

        int ans = 0;
        for(int i : st){
            
            int curr = 0;
            if(!st.count(i - 1)){

                while(st.count(i)){
                    curr++;
                    i++;
                }
            }
            ans = max(ans , curr);
        }
        return ans;
    }
};