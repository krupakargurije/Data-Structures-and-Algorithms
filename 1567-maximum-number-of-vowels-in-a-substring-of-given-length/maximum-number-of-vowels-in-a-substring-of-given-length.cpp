class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        if(n == 0)return 0;
        
        unordered_set<char>st = {'a' , 'e' , 'i' , 'o' ,'u'};
        int ans = 0, i = 0,count = 0;

        for(int j = 0;j<k;j++){
            if(st.count(s[j]))count++;
        }
        ans = max(ans , count);

        for(int j = k;j<n;j++){
            if(st.count(s[j]))count++;
            if(st.count(s[i]))count--;
            i++;

            ans = max(ans , count);
        }
        return ans;
    }
};