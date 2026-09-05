class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &text1, string &text2,int n,int m){
        if (m<1 || n<1){
            return 0;
        }
        if (dp[n][m]!=-1){
            return dp[n][m];
        }
        if (text1[n-1]==text2[m-1]){
            return dp[n][m]=max(1+solve(text1,text2,n-1,m-1),solve(text1,text2,n-1,m-1));
        }
        else{
            return dp[n][m]=max(solve(text1,text2,n-1,m),solve(text1,text2,n,m-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size()+1,vector<int>(text2.size()+1,-1));
        return solve(text1,text2,text1.size(),text2.size());
    }
};
