class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size()-1;
        bitset<201>visit;
        bool duplicate=0;

        for(auto &num:nums){
            if(num>n) return false;
            if(visit.test(num)){
                if(num<n || duplicate) return false;
                duplicate|=1;
                continue;
            }
            visit.set(num);
        }
        return true;
    }
};