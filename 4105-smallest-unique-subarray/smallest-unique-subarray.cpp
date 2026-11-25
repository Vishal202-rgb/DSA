class Solution {
public:
    typedef unsigned long long ull;
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        ull base=1000003;
        vector<ull>hash(n+1,0);
        vector<ull>po(n+1,1);

            for(int i=0;i<n;i++){
                hash[i+1]=hash[i]*base+nums[i]+7;
                po[i+1]=po[i]*base;
                }
                auto subarrayHash=[&](int l,int r){
                    return hash[r+1]-hash[l]*po[r-l+1];
                };
        int low=1,high=n;
        int ans=n;

        while(low<=high){
            int len=(low+high)/2;
            unordered_map<ull,int>freq;

                for(int start=0;start+len<=n;start++){
                    ull curr=subarrayHash(start,start+len-1);
                    freq[curr]++;
                }
            bool found=false;
            for(int start=0;start+len<=n;start++){
                ull curr=subarrayHash(start,start+len-1);
                if(freq[curr]==1) {
                    found=true;
                    break;
            }
        }
            if(found){
                ans=len;
                high=len-1;
            }else{
                low=len+1;
            }
        }
        return ans;
    }
};