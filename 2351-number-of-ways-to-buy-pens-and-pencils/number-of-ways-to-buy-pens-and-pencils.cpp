class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    return total < 0 ? 0 : 1 + total / cost2 + waysToBuyPensPencils(total - cost1, cost1, cost2);
}
};