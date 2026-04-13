class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        unordered_set<int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==j||j==k||i==k) continue;
                    int nums=digits[i]*100+digits[j]*10+digits[k];
                    if(nums>=100 && nums%2==0) mp.insert(nums);
                }
            }
        }
        vector<int>ans(begin(mp),end(mp));
        sort(begin(ans),end(ans));
        return ans;
    }
};