class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , vector<long long>>pref;
        unordered_map<int , vector<int>>idx;

        for(int i = 0; i < n; i++){
            int val = nums[i];

            idx[val].push_back(i);

            if(pref[val].empty()){
                pref[val].push_back(i);
            } else {
                pref[val].push_back(pref[val].back() + i);
            }
        }

        vector<long long> ans(n);

        for(auto &p : idx){
            int val = p.first;
            vector<int> &v = p.second;
            vector<long long> &pre = pref[val];

            int k = v.size();

            for(int i = 0; i < k; i++){
                long long left = 0, right = 0;

                if(i > 0){
                    left = (long long)v[i] * i - pre[i-1];
                }

                if(i < k-1){
                    right = (pre[k-1] - pre[i]) - (long long)v[i] * (k-i-1);
                }
                ans[v[i]] = left + right;
            }
        }
        return ans;
    }
};