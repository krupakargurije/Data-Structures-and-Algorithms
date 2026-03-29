class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        long long sum = 0;

        for(int left = k - 1; left >= 0;left--){
            sum += arr[left];
        }

        long long ans = 0;
        int left = k-1;
        ans = max(ans , sum);
        for(int right = n-1;right >= n - k;right--){
            sum -= arr[left];
            sum += arr[right];
            left--;
            ans = max(ans , sum);
        }
        return (int)ans;
    }
};