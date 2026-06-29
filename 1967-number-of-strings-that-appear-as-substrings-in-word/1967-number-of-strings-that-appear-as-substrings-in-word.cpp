class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.length();
        int ans = 0;

        for(string str : patterns){
            int l = str.length();
            for(int i = 0;i<=n - l;i++){
                if(str == word.substr(i , l)){
                    ans++;
                    break;
                };
            }
        }
        return ans;
    }
};