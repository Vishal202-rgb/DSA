class Solution {
public:
    void rotate(string &s, int b) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
    }
    string findLexSmallestString(string s, int a, int b) {
        string small=s;
        unordered_set<string>visited;
        queue<string>que;
        que.push(s);
        visited.insert(s);

        while(!que.empty()){
            string curr=que.front();
            que.pop();

            if(curr<small){
                small=curr;
            }
            string temp=curr;
            for(int i=1;i<temp.length();i+=2){
                temp[i]=((temp[i]-'0'+a)%10)+'0';
            }

            if(!visited.count(temp)){
                visited.insert(temp);
                que.push(temp);
            }
            rotate(curr,b);
            if(!visited.count(curr)){
                visited.insert(curr);
                que.push(curr);
            }
        }
        return small;
    }
};