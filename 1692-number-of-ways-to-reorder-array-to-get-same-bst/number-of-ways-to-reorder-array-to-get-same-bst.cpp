class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;
    vector<vector<ll>> mp;
    int solve(vector<int>& nums) {
        int m = nums.size();
        if(m < 3)
            return 1;
        
        vector<int> left, right;
        
        int root = nums[0];
        for(int i = 1; i < m; i++) {
            
            if(nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        ll leftways  = solve(left)  % MOD;
        ll rightways = solve(right) % MOD;
        
        return (((leftways * rightways)%MOD) * mp[m-1][left.size()]) % MOD;   
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size(); 
        mp.resize(n+1);
        
        for(int i = 0; i <= n; i++) { 
            mp[i] = vector<long long>(i+1, 1);
            for(int j = 1; j < i; j++) {
                mp[i][j] = (mp[i-1][j-1] + mp[i-1][j]) % MOD;
            }
        } 
        return (solve(nums)-1) % MOD;
    }
};