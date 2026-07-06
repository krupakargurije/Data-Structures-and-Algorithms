class Solution {
    private:
    void trim(string &s){
        int n = s.length();
        int i = 0 , j = 0;

        while(j < n){
            //remove leading spaces
            while(j < n && s[j] == ' ')
                j++;

            while(j < n && s[j] != ' ')
                s[i++] = s[j++];
            
            while(j < n && s[j] == ' ')
                j++;

            if(j < n )
                s[i++] = ' ';
        }
        s.resize(i);
    }
public:
    string reverseWords(string s) {
        trim(s);

        reverse(s.begin(), s.end());
        int start = 0;

        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};