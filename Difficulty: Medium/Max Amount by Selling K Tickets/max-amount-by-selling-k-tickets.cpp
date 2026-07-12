class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        priority_queue<int> pq(arr.begin(), arr.end());
        
        int ans = 0;
        int MOD = 1e9 + 7;
        
        while (k > 0 && pq.top() > 0) {
            
            int ele = pq.top();
            pq.pop();
            
            ans = (ans + ele) % MOD;
            
            ele--;
            pq.push(ele);
            
            k--;
        }
        
        return ans;
    }
};