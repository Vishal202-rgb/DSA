class SegmentTree{
    private:
    int n;
    int size;
    vector<int> min_tree;
    vector<int> max_tree;
    vector<int> lazy;
    void push(int idx, int l, int r){
        if(lazy[idx] != 0){
            min_tree[idx] += lazy[idx];
            max_tree[idx] += lazy[idx];
            if(l<r){
                lazy[2 * idx] += lazy[idx];
                lazy[2 * idx + 1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }
    void updateRange(int l, int r, int delta, int idx, int segL, int segR){
        push(idx, segL, segR);
        if(r<segL || l>segR)return;
        if(l <= segL && segR <= r){
            lazy[idx] += delta;
            push(idx, segL, segR);
            return ;

        }
        int mid = (segL + segR)/2;
        updateRange(l,r, delta, 2*idx, segL,mid);
        updateRange(l, r, delta, 2*idx+1, mid +1, segR);
        min_tree[idx] =min(min_tree[2* idx], min_tree[2*idx+1]);
        max_tree[idx] = max(max_tree[2*idx], max_tree[2*idx+1]);
    }
    int queryFirstZero(int l, int r, int idx, int segL, int segR){
        push(idx, segL, segR);
        if(r< segL || l>segR) return -1;
        if(min_tree[idx]> 0 || max_tree[idx] < 0) return -1;
        if(segL == segR){
            if(min_tree[idx] == 0)return segL;
            else return -1;
        }
        int mid = (segL+ segR)/2;
        int left_res = queryFirstZero(l,r,2*idx, segL, mid);
        if(left_res != -1) return left_res;
        int right_res = queryFirstZero(l, r, 2*idx+1, mid+1, segR);
        return right_res;
    }
    public:
    SegmentTree(int n): n(n){
        size = 1;
        while(size< n) size *= 2;
        min_tree.resize(2*size, 0);
        max_tree.resize(2*size, 0);
        lazy.resize(2 * size, 0);
    }
    void updateRange(int l, int r, int delta){
        updateRange(l, r, delta, 1, 0, size-1);

    }
    int queryFirstZero(int l, int r){
        return queryFirstZero(l, r, 1, 0, size-1);
    }
};
class Solution{
    public:
    int longestBalanced(vector<int>&nums){
        int n = nums.size();
        SegmentTree segTree(n);
        unordered_map<int, int> lastOccur;
        int maxLen = 0;
        for(int j = 0; j<n; j++){
            int v = nums[j];
            int old_f = -1;
            if(lastOccur.find(v)!= lastOccur.end()){
                old_f = lastOccur[v];
            }
            int l = old_f+1;
            int r = j;
            if(v%2 == 1){
                segTree.updateRange(l,r, 1);
            }else{
                segTree.updateRange(l, r, -1);
            }
            lastOccur[v] =j;
            int i = segTree.queryFirstZero(0, j);
            if(i != -1){
                int len = j-i+1;
                maxLen = max(maxLen , len);
            }
        }
        return maxLen;
    }
};