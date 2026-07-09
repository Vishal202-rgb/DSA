class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>cComp(n,0);
        int curr=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                curr++;
            }
            cComp[i]=curr;
        }
        vector<bool>res(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            if(cComp[queries[i][0]]==cComp[queries[i][1]]) res[i]=1;
        }
        return res;
    }
};