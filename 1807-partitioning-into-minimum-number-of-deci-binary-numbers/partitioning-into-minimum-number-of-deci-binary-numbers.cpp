class Solution {
public:
    int minPartitions(string n) {
        char max=*max_element(begin(n),end(n));
        return max-'0';
    }
};