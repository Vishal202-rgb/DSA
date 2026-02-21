class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=target.size();

        sort(begin(target),end(target));
        sort(begin(arr),end(arr));

        for(int i=0;i<n;i++){
            if(target[i]!=arr[i]) return false;
        }
        return true;
    }
};