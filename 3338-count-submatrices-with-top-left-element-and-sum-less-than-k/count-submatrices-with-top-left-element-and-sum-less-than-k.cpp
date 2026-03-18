class Solution {
public:
    int countSubmatrices(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> prefSum(n , vector<int>(m , 0));
        int ans = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                prefSum[i][j] = arr[i][j];

                if(i > 0)prefSum[i][j] += prefSum[i-1][j];
                if(j > 0)prefSum[i][j] += prefSum[i][j-1];

                if(i > 0 && j > 0)prefSum[i][j] -= prefSum[i - 1][j-1];

                if(prefSum[i][j] <= k)ans++;
                else break;
            }
        }
        return ans;
    }
};