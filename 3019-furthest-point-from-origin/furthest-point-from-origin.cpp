class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int x = 0;
        int count = 0;  
        
        // Single pass to compute net and wildcards
        for (char &ch:moves) {
            if (ch == 'L') x++;     // 'L' increases left bias (towards negative)
            else if (ch == 'R') x--; // 'R' increases right bias (towards positive)
            else count++;           // '_' can go either way
        }
        // Max distance: all '_' align to maximize |position|
        return max(abs(x + count), abs(x - count));  
    }
};