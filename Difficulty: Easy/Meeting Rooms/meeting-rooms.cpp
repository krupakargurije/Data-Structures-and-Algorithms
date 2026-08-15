class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        int n = arr.size();
        sort(arr.begin() , arr.end());
        
        for(int i = 1;i<n;i++){
            if(arr[i - 1][1] > arr[i][0])return false;
        }
        return true;
    }
};