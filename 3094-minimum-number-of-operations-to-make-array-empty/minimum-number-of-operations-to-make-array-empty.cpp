class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(int &num:nums){
            mp[num]++;
        }
        int move=0;
        for(auto &it:mp){
            int count=it.second;

            if(count==1) return -1;
            if(count%3==0) move+=count/3;
            else move+=(count/3)+1;
        }
        return move;
    }
};