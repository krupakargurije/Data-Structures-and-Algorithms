class Solution {
  public:
    bool canRepresentBST(vector<int> &nums) {
        int n = nums.size();
        int root = INT_MIN;
        stack<int>st;
        
        for(int i = 0;i<n;i++){
            if(nums[i] < root)
                return false;
                
            while(!st.empty() && st.top() < nums[i]){
                root = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return true;
    }
};