class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int count=0;
        int n= nums1.size();
        unordered_map<int,int>mp;

        for(auto it: nums1){
            mp[it]++;  
        }
        for(auto it: nums2){
            mp[it]--;
        }
        for(auto it: mp){
            if(it.second %2 != 0)return -1;
            else{
                count+= abs(it.second)/2;
            }
        }
        return count/2;  
    }
};