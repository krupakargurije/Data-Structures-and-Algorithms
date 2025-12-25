class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        int n = arr.size();
        int neg = 0;
        long long ans = 0;
        sort(arr.begin(),arr.end());


        for(int i = n-1;i>= n - k && i >= 0;i--){
            ans += max(0, arr[i] - neg);
            neg++;
        }
        return ans;
    }
};