/*Easy to understand solution (Modified version of Kadane's Algo with at each index two option keep and remove)*/
class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int ans = arr[0], keep = arr[0], rem = 0;
        
        for (int i = 1; i < n; i++) {
            rem = max(rem + arr[i], keep);
            keep = max(keep + arr[i], arr[i]);
            
            ans = max({ans, keep, rem});
        }
        return ans;
    }
};

