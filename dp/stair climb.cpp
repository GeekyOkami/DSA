class Solution {
public:

    int solve(int n,vector<int> &dp){
        dp[n]=1;
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            dp[i]=dp[i+1]+dp[i+2];
        }

        return dp[0];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1);
        int ans=solve(n,dp);
        return ans;
    }
};