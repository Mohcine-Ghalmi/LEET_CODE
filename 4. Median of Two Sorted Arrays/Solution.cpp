class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.size() + nums2.size());

        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());
        sort(merged.begin(), merged.end());

        if (merged.size() % 2 != 0)
            return (merged[round(merged.size() / 2)]);

        double val = merged[round(merged.size() / 2) - 1] + merged[round(merged.size() / 2)];
        return (val / 2.0);
    }
};