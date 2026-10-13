class Solutions{
    public:
    long long helper(vector<int>& nums){
        int n = nums.size();
        vector<long long> arr1, arr2;
        vector<long long> sq;
        
        for (int i = 0; i < n; i++) 
            sq.push_back(1LL * nums[i] * nums[i]);
        
        sort(sq.begin(), sq.end());

        int l = 0, r = n - 1;

        vector<long long> arr;
        
        while (l <= r) {
            if (l == r) arr.push_back(sq[r--]);
            else {
                arr.push_back(sq[r--]);
                arr.push_back(sq[l++]);
            }
        }
        long long ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) ans += arr[i];
            else ans -= arr[i];
        }
        return ans;
    }
};
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        Solutions s;
        long long ans = s.helper(nums);
        return ans;
    }
};