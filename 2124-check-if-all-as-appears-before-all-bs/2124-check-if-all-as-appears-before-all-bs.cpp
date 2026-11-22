class Solution {
public:
    bool checkString(string s) {
        bool find = false;
        for(char c : s){
            if(c == 'b')
                find = true;
            if(find && c == 'a')
                return false;
        }
        return true;
    }
};