class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i = 0, j = 0;

        for (; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] <= nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            } else {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
            arr.push_back(nums1[i++]);
        }
        while (j < nums2.size()) {
            arr.push_back(nums2[j++]);
        }

        int n = arr.size();
        if (n % 2 == 1) {
            return arr[n / 2];
        } else {
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        }
    }
};
