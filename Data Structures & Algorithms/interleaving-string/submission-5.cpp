class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string &s1, string &s2, string &s3,int n,int m,int k){
        if (k==0){
            if (n==0 && m==0){
                return true;
            }
        }
        if (n==0){
            return s2.substr(0,m)==s3.substr(0,k);
        }
        if (m==0){
            return s1.substr(0,n)==s3.substr(0,k);
        }
        if (dp[n][m]!=-1){
            return dp[n][m];
        }
        bool a1=false;
        bool a2=false;
        if (s3[k-1]==s1[n-1]){
            a1=solve(s1,s2,s3,n-1,m,k-1);
        }
        if (s3[k-1]==s2[m-1]){
            a2=solve(s1,s2,s3,n,m-1,k-1);
        }
        return dp[n][m]=a1 || a2;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        dp.assign(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,s3,s1.size(),s2.size(),s3.size());
    }
};
