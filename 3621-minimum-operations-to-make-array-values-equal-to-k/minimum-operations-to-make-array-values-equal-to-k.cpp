class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> pp;

        for(int &num : nums) {
            if(num < k) {
                return -1;
            } else if(num > k) {
                pp.insert(num);  
            }
        }
        return pp.size();
    }
};