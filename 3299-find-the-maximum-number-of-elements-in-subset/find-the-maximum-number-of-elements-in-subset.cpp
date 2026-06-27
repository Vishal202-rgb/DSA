class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &num:nums){
            mp[num]++;
        }
        int ans=(mp[1]-1)|1;
        mp.erase(1);

        for(auto &m:mp){
            int num=0,x=m.first;

            int sq=sqrt(x);
            if(sq*sq==x && mp.count(sq) && mp[sq]>1) continue;

            while(x<31623 && mp.count(x) && mp[x]>1){
                num+=2;
                x*=x;
            }
            ans=fmax(ans,num+((mp.count(x)<<1)-1));
        }
        return ans;
    }
};