class Solutions{
    public:
    int helper(string s){
        string str = s;
        int n = str.size();
        int maxlen = 0;

        for(int i = 0;i<n;i++){
            vector<int> mp(26,0);
            int dis = 0;
            for(int j = i;j<n;j++){
                int idx = str[j] - 'a';
                mp[idx]++;

                int val = 0;
                bool bal = true;

                for(int k = 0;k<26;k++){
                    if(mp[k] > 0){
                        if(val == 0){
                            val = mp[k];
                        }else if(mp[k] != val){
                            bal = false;
                            break;
                        }
                    }
                }
                if(bal){
                    maxlen = max(maxlen,j - i + 1);
                }
            }
        }
        return maxlen;
    }
};

class Solution {
public:
    int longestBalanced(string s) {
        Solutions st;
        int ans = st.helper(s);
        return ans;
    }
};