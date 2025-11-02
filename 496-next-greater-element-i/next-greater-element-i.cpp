class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            bool found = false;
            int nextGreater = -1;

            for (int j = 0; j < m; j++) {
                if (nums2[j] == nums1[i]) found = true;

                if (found && nums2[j] > nums1[i]) {
                    nextGreater = nums2[j];
                    break;
                }
            }
            ans.push_back(nextGreater);
        }

        return ans;
    }
};
