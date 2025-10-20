class Solution {
    private:
    pair<int,int> helper(string s, int left,int right){
        while(left >=0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return {left + 1,right - 1};
    }
public:
    string longestPalindrome(string s) {
        int ans = 0,n = s.length();
        int start = 0,end = 0;

        for(int i = 0;i<n;i++){
            auto [l1,r1] = helper(s,i,i);
            auto [l2,r2] = helper(s,i,i+1);

            if(r1 - l1 > end - start){
                start = l1;
                end = r1;
            }
            if(r2 - l2 > end - start){
                start = l2;
                end = r2;
            }
        }
        return s.substr(start,end - start +1);
    }
};