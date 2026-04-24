class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int start = 0;
        int count = 0;
        for(char c : moves){
            if(c == '_')count++;

            if(c == 'L')start--;
            else if(c == 'R')start++;
        }
        return abs(start) + count;
    }
};