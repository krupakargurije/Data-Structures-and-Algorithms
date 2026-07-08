class Solutions{
    public:
    vector<int> helper(string s, vector<vector<int>>& q){
        const long long mod = 1000000007;
        int n = s.size(), m = q.size();
        
        vector<long long> arr1(n+1,0), arr2(n+1,0), arr3(n+1,1), arr4(n+1,0);
        
        for(int i=0;i<n;i++){
            arr3[i+1] = (arr3[i] * 10) % mod;
            arr4[i+1] = arr4[i] + (s[i] != '0');
            if(s[i] != '0'){
                int d = s[i] - '0';
                arr1[i+1] = (arr1[i] * 10 + d) % mod;
                arr2[i+1] = arr2[i] + d;
            } else {
                arr1[i+1] = arr1[i];
                arr2[i+1] = arr2[i];
            }
        }
        
        vector<int> ans;
        ans.reserve(m);
        
        for(auto &v : q){
            int l = v[0], r = v[1];
            int c = arr4[r+1] - arr4[l];
            if(c == 0){
                ans.push_back(0);
                continue;
            }
            long long x = (arr1[r+1] - (arr1[l] * arr3[c]) % mod + mod) % mod;
            long long sm = arr2[r+1] - arr2[l];
            ans.push_back((x * (sm % mod)) % mod);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        Solutions sf;
        vector<int> ans = sf.helper(s,q);
        return ans;
    }
};