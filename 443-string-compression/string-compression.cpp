class Solution {
public:
    int compress(vector<char>& arr) {
        int n = arr.size();
        int write = 0;
        
        for (int i = 0; i < n; ) {
            char c = arr[i];
            int count = 0;

            while (i < n && arr[i] == c) {
                i++;
                count++;
            }

            arr[write++] = c;

            if (count > 1) {
                string s = to_string(count);
                for (char x : s) arr[write++] = x;
            }
        }
        return write;
    }
};
