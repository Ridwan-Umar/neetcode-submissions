class Solution {
public:
    vector<vector<int>>dp;
    bool solve(vector<int>& nums,int n,int sum){
        if (n<=0){
            if (sum==0){
                return dp[n][sum]=1;
            }
            else{
                return dp[n][sum]=0;
            }
        }
        if (dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if (nums[n-1]<=sum){
            return dp[n][sum]=solve(nums,n-1,sum-nums[n-1]) || solve(nums,n-1,sum);
        }
        else{
            return dp[n][sum]=solve(nums,n-1,sum);
        }
        // return dp[n][sum]=0;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if (sum%2!=0){
            return false;
        }
        dp.assign(nums.size()+1,vector<int>(sum/2+1,-1));
        return solve(nums,nums.size(),sum/2);
    }
};