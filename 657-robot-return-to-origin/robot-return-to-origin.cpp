class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int , int> curr = {0 , 0};

        for(char &c : moves){
            if(c == 'U'){
                curr.first -= 1;
            }
            else if(c == 'R'){
                curr.second += 1;
            }
            else if(c == 'D'){
                curr.first += 1;
            }
            else{
                curr.second -= 1;
            }
        }
        return curr == pair<int , int>{0 , 0};
    }
};