class Solution {
public:
    bool checkValidString(string s) {
        int mn = 0 , mx = 0;

        for(char c : s){
            if(c == '('){
                mn++;
                mx++;
            }
            else if(c ==')'){
                mn--;
                mx--;
            }
            else{
                mn--;
                mx++;
            }

            if(mn < 0)mn = 0;
            if(mx < 0)return false;
        }
        return mn == 0;
    }
};