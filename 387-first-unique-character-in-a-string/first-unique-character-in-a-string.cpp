class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        queue<int>q;

        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                q.push(i);
            }
            mp[s[i]]++;
            while(q.size()>0 && mp[s[q.front()]]>1){
                q.pop();
            }
        }
        if(q.empty()) return -1;
        return q.front();
    }
};