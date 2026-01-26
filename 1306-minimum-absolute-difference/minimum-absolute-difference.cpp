class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(begin(arr),end(arr));
        
       int minDiff=INT_MAX;
       for(int i=1;i<n;i++){
        minDiff=min(minDiff,arr[i]-arr[i-1]);
       }
       vector<vector<int>>ans;
       for(int i=1;i<n;i++){
        int diff=arr[i]-arr[i-1];

        if(diff==minDiff){
            ans.push_back({arr[i-1],arr[i]});
        }
       }
        return ans;
    }
};