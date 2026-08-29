class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>vec=nums;
        sort(begin(vec),end(vec));

        int grpNum=0;
        unordered_map<int,int>numToGrp;
        numToGrp[vec[0]]=grpNum;

        unordered_map<int,list<int>>grpToList;
        grpToList[grpNum].push_back(vec[0]);

        for(int i=1;i<n;i++){
            if(abs(vec[i]-vec[i-1])>limit){
                grpNum+=1;
            }
            numToGrp[vec[i]]=grpNum;
            grpToList[grpNum].push_back(vec[i]);
        }
        vector<int>res(n);
        for(int i=0;i<n;i++){
            int num=nums[i];
            int group=numToGrp[num];
            res[i]=*(grpToList[group].begin());
            grpToList[group].pop_front();
        }
        return res;
    }
};