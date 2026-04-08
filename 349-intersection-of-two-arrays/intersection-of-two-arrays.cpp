class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        set<int> st;
        vector<int> ans;

        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] == nums2[j]) {
                st.insert(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        for (auto &num : st) {
            ans.push_back(num);
        }
        return ans;
    }
};