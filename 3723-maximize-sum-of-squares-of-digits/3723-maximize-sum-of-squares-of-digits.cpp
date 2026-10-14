class Solutions{
    public:
    string helper(int num, int sum){
        if(sum > 9 * num)return "";

        string ans = "";

        for(int i = 0;i<num;i++){
            int d = min(9,sum);
            ans.push_back('0' + d);
            sum -= d;
        }
        if(sum != 0)return "";
        return ans;
    }
};

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        Solutions s;
        string ans = s.helper(num,sum);
        return ans;
    }
};