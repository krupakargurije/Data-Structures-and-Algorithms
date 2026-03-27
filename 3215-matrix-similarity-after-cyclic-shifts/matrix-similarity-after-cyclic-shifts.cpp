class Solution {
    private:
    vector<int> leftRotate(vector<int> &arr){
        int n = arr.size();

        vector<int> ans;
        for (int i = 1; i < n; i++) ans.push_back(arr[i]);
        ans.push_back(arr[0]);

        return ans;
    }

    vector<int> rightRotate(vector<int> &arr){
        int n = arr.size();

        vector<int> ans;
        ans.push_back(arr[n-1]);
        for (int i = 0; i < n - 1; i++) ans.push_back(arr[i]);

        return ans;
    }
public:
    bool areSimilar(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<int>> ans = arr;
        k %= m;

        while(k--){
            for(int i = 0;i<n;i++){
                if(i % 2){
                    ans[i] = rightRotate(ans[i]);
                }
                else{
                    ans[i] = leftRotate(ans[i]);
                }
            }
        }

        return ans == arr;
    }
};