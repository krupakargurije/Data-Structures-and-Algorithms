class Solution {
public:
    int addDigits(int num) {
        string str = to_string(num);
        while(str.length() > 1){
            num = 0;
            for(char c : str){
                num += c - '0';
            }
            str = to_string(num);
        }
        return num;
    }
};