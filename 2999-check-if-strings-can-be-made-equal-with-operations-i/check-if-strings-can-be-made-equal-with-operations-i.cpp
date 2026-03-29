class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2)return true;

        for(int i = 0;i<4;i++){
            if(s1[i] == s2[i])continue;
            if(i + 2 < 4){
                swap(s1[i] , s1[i + 2]);
            }
        }
        return s1 == s2;
    }
};