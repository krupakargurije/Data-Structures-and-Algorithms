class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if((n - k + 1) < pow(2,k))return false;

        unordered_set<string>st;

        for(int i = 0;i < n-k + 1;i++){
            string t = s.substr(i,k);
            st.insert(t);
            if(st.size() == pow(2,k))return true;
        }
        return false;
    }
};