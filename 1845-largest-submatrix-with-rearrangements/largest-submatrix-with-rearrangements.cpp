class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& arr) {
        int n = arr.size(),m = arr[0].size();

        for(int i = 1;i<n;i++){
            for(int j = 0;j<m;j++){
                if(arr[i][j])
                    arr[i][j] += arr[i-1][j];
            }
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            sort(arr[i].rbegin(), arr[i].rend());

            for(int j = 0;j<m;j++){
                ans = max(ans , arr[i][j] * (j + 1));
            }
        }
        return ans;
    }
};