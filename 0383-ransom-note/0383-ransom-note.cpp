class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = magazine.length();
        if(ransomNote.length() > n)return 0;

        vector<int>mp(28 , 0);

        for(char c : magazine){
            mp[c - 'a']++;
        }

        for(int i = 0;i<ransomNote.length();i++){
            char c = ransomNote[i];
            if(mp[c - 'a'] < 1)
                return 0;
            mp[c - 'a']--;
        }
        return true;
    }
};