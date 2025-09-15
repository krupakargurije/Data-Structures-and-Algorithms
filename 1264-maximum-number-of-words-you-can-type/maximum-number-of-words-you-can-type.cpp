class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.length();
        int ans = 0;
        unordered_map<char,int> mp;
        for(char i :brokenLetters){
            mp[i]++;
        }

        bool canType = true;
        for(int i = 0;i<n;i++){
            if(text[i] == ' '){
                if(canType)ans++;
                canType = true;
            }
            else{
                if(mp[text[i]])canType = false;
            }
        }
        if(canType)ans++;
        return ans;
    }
};