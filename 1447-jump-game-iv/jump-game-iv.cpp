class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        vector<bool>visit(n,false);

        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>que;
        que.push(0);
        visit[0]=true;

        int steps=0;

        while(!que.empty()){
            int size=que.size();

            while(size--){
                int curr=que.front();
                que.pop();

                int left=curr-1;
                int right=curr+1;

                if(curr==n-1) return steps;

                if(left>=0 && !visit[left]){
                    que.push(left);
                    visit[left]=true;
                }
                if(right<=n-1 && !visit[right]){
                    que.push(right);
                    visit[right]=true;
                }
                for(int &idx:mp[arr[curr]]){
                    if(!visit[idx]){
                        que.push(idx);
                        visit[idx]=true;
                    }
                }
                mp.erase(arr[curr]);
            }
            steps++;
        }
        return -1;
    }
};