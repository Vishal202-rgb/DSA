class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(arr[i]==0){
                ans.push_back(0);
                ans.push_back(0);
            }else{
                ans.push_back(arr[i]);
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=ans[i];
        }
    }
};