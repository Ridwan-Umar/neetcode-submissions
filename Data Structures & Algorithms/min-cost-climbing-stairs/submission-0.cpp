class Solution {
public:
    vector<int>dp;
    int solve(vector<int>& cost,int i){
        if (i>=cost.size()){
            return 0;
        }
        if (dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=min(cost[i]+solve(cost,i+1),cost[i]+solve(cost,i+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.assign(cost.size()+1,-1);
        return min(solve(cost,0),solve(cost,1));
    }
};
