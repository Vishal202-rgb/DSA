class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            int sum = 0;
        for(int j = i;j<n;j++){
            sum += arr[j];
            if((j-i)%2==0){
            ans+=sum;
            }
        }
    }
    return ans ;
}
};