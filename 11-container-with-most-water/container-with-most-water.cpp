class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int j = n-1,i = 0;
        int ans = 0;
        
        while(i <= j){
            int len = j - i;
            ans = max(ans , len * min(arr[i] , arr[j]));
            
            if(arr[i] < arr[j])i++;
            else j--;
        }
        return ans;
    }
};