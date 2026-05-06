class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;
        
        vector<int>mp1(27 , 0) , mp2(27 , 0);

        for(int i = 0;i<s.length();i++){
            mp1[s[i] - 'a']++;
            mp2[t[i] - 'a']++;
        }
        for(int i = 0;i<27;i++){
            if(mp1[i] != mp2[i])
                return false;
        }
        return true;
    }
};