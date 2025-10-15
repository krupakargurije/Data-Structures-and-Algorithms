class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);
        int left = 0, right = n - 1;
        int idx = n - 1;
        
        while (left <= right) {
            int leftSq = a[left] * a[left];
            int rightSq = a[right] * a[right];
            
            if (leftSq > rightSq) {
                ans[idx--] = leftSq;
                left++;
            } else {
                ans[idx--] = rightSq;
                right--;
            }
        }
        
        return ans;
    }
};