class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        long long ans = 0;

        for (int x : arr) {
            int rem = x % k;
            int need = (k - rem) % k;

            ans += freq[need];
            freq[rem]++;
        }
        return ans;
    }
};