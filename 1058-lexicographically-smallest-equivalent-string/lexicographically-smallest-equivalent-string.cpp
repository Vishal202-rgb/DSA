class Solution {
public: 
    char DFS(unordered_map<char,vector<char>>&adj,char ch,vector<int>&visited){
        visited[ch-'a']=1;
        char minChar=ch;

        for(char &v:adj[ch]){
            if(visited[v-'a']==0){
                minChar=min(minChar,DFS(adj,v,visited));
            }
        }
        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();
        int m=baseStr.length();
        unordered_map<char,vector<char>>adj;

        for(int i=0;i<n;i++){
            char u=s1[i];
            char v=s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string res;
        for(int i=0;i<m;i++){
            char ch=baseStr[i];
            vector<int>visited(26,0);
            char minChar=DFS(adj,ch,visited);
            res.push_back(minChar);
        }
        return res;
    }
};