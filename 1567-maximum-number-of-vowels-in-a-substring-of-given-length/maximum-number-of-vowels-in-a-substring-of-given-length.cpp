class Solution {
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        if(n == 0)return 0;
        
        int ans = 0, i = 0,count = 0;

        for(int j = 0;j<k;j++){
            if(isVowel(s[j]))count++;
        }
        ans = max(ans , count);

        for(int j = k;j<n;j++){
            if(isVowel(s[j]))count++;
            if(isVowel(s[i]))count--;
            i++;

            ans = max(ans , count);
        }
        return ans;
    }
};