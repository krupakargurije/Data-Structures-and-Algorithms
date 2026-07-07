using ll = long long;
class Solution {
public:
    long long sumAndMultiply(int n) {
        ll sum = 0 , num = 0;
        string str = to_string(n);

        for(char c : str){
            if(c != '0'){
                int digit = c - '0';
                sum += digit;
                num = num * 10 + digit;
            }
        }
        return sum * num;
    }
};