class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& arr) {
        int n = arr.size();
        long long ans = 0;
        int count = 0,Neg = INT_MAX;

        for(int i = 0;i<n;i++){
            for(int k =0;k < n;k++){
                if(arr[i][k] < 0)count++;
                ans += abs(arr[i][k]);
                Neg = min(Neg,abs(arr[i][k]));
            }
        }
        if(count % 2 != 0)ans -= 2 * Neg;
        return ans;
    }
};