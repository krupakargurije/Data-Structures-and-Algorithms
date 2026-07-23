class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        string st;
        
        for(int i = 0;i<n;i++){
            while(!st.empty() && st.back() > nums[i] && k){
                st.pop_back();
                k--;
            }

            st.push_back(nums[i]);
        }

        while(k--)
            st.pop_back();

        int idx = 0;
        while(idx < st.size() && st[idx] == '0')idx++;

        string ans = st.substr(idx);
        return ans.empty() ? "0" : ans;
    }
};