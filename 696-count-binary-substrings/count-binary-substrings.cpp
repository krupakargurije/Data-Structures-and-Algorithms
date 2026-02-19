class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int ans = 0;
        int i = 0,j = 0;
        vector<int>arr;
        
        while(i < n){
            if(s[i] == s[j])i++;
            else if(s[i] != s[j]){
                arr.push_back(i - j);
                j = i;
            }
        }
        arr.push_back(i - j);

        for(int k = 1;k<arr.size();k++){
            ans += min(arr[k],arr[k-1]);
        }
        return ans;
    }
};