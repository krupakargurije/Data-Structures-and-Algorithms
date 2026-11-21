class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char , string>wordToStr;
        unordered_map<string , char>StringToChar;
        int idx = 0;

        for(int i = 0;i<pattern.length();i++){
            char c = pattern[i];

            if(idx >= s.length())
                return false;

            string str = "";
            while(idx < s.length() && s[idx] != ' '){
                str += s[idx++];
            }
            idx++;

            if(wordToStr.count(c) && wordToStr[c] != str)
                return false;
            if(StringToChar.count(str) && StringToChar[str] != c)
                return false;

            wordToStr[c] = str;
            StringToChar[str] = c;
        }
        return idx >= s.length();
    }
};