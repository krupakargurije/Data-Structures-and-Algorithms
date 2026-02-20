class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int i = 0,j = n-1,curr = 0;

        while(curr <= j){
            if(arr[curr] == 0)swap(arr[i++],arr[curr++]);

            else if(arr[curr] == 1)curr++;

            else swap(arr[curr],arr[j--]);
        }
    }
};