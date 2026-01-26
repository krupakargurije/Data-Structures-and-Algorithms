class Solution {
    int helper(vector<int>& arr){
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int ans = INT_MAX;
        for(int i = 0; i < n - 1; i++){
            ans = min(ans, arr[i+1] - arr[i]);
        }
        return ans;
    }

public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int smallNum = helper(arr);
        int n = arr.size();

        vector<vector<int>> ans;
        for(int i = 0; i < n - 1; i++){
            if(arr[i+1] - arr[i] == smallNum){
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};