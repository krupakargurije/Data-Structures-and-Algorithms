class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &q) {
        int n = arr.size();
        vector<int> inc(n , n-1) , dec(n , 0);
        
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1])
                inc[i] = inc[i + 1];
            else
                inc[i] = i;
        }
        
        for(int i = 1;i<n;i++){
            if(arr[i - 1] >= arr[i]){
                dec[i] = dec[i - 1];
            }
            else{
                dec[i] = i;
            }
        }
        
        vector<bool>ans;
        for(auto it : q){
            int l = it[0];
            int r = it[1];
            
            ans.push_back(dec[r] <= inc[l]);
        }
        return ans;
    }
};