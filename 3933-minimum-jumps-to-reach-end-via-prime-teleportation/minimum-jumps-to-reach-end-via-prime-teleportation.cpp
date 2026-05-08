class Solution {
private:

    vector<bool> isPrime;

    void sieve(int mx) {

        isPrime.resize(mx + 1, true);

        if(mx >= 0) isPrime[0] = false;
        if(mx >= 1) isPrime[1] = false;

        for(int i = 2; i * i <= mx; i++) {

            if(isPrime[i]) {

                for(int j = i * i; j <= mx; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

public:

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());

        sieve(mx);

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        queue<pair<int,int>> q;
        vector<bool> vis(n, false);

        unordered_set<int> usedPrime;

        q.push({0, 0});
        vis[0] = true;

        while(!q.empty()) {

            auto [idx, jumps] = q.front();
            q.pop();

            if(idx == n - 1)
                return jumps;

            // left
            if(idx - 1 >= 0 && !vis[idx - 1]) {
                vis[idx - 1] = true;
                q.push({idx - 1, jumps + 1});
            }

            // right
            if(idx + 1 < n && !vis[idx + 1]) {
                vis[idx + 1] = true;
                q.push({idx + 1, jumps + 1});
            }

            int val = nums[idx];

            if(isPrime[val] && !usedPrime.count(val)) {

                usedPrime.insert(val);

                for(int multiple = val; multiple <= mx; multiple += val) {

                    if(mp.count(multiple)) {

                        for(int nextIdx : mp[multiple]) {

                            if(!vis[nextIdx]) {

                                vis[nextIdx] = true;
                                q.push({nextIdx, jumps + 1});
                            }
                        }

                        // important optimization
                        mp.erase(multiple);
                    }
                }
            }
        }

        return -1;
    }
};