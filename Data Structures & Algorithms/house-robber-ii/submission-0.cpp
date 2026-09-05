class Solution {
public:
    vector<int>dp;
    int solve(vector<int>& nums,int i,int check){
        if (i<check){
            return 0;
        }
        if (dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=max(nums[i]+solve(nums,i-2,check),solve(nums,i-1,check));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1){
            return nums[0];
        }
        dp.assign(n+1,-1);
        int ans1=solve(nums,n-1,1);
        dp.assign(n+1,-1);
        int ans2=solve(nums,n-2,0);
        return max(ans1,ans2);
    }
};