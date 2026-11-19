class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.length();

        if(s.empty())return true;

        for(int i = n - 1;i>=0;i--){
            if(s.empty())
                return true;

            if(t[i] == s.back())
                s.pop_back();
        }
        return s.empty();
    }
};