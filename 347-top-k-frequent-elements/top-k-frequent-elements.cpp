class Solution {
public:
    typedef pair<int,int>p;
    vector<int> topKFrequent(vector<int>&nums,int k) {
        priority_queue<p, vector<p>, greater<p>> pq;
        
        unordered_map<int, int> mp;
        for(int &x:nums)
            mp[x]++;
        
        //Push in min-heap and maintain size k
        for(auto &it:mp) {
            pq.push({it.second, it.first});
            
            if(pq.size()>k)
                pq.pop();
        } 
        //Pick all top K elements
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};