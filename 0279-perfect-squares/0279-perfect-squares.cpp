class Solution {
public:
    int helper(int n, vector<int>&dp){
        if(n == 0 ) return 0;
        if(n<0) return INT_MAX;
        int minm = INT_MAX;
        if(dp[n] != -1) return dp[n];
        for(int i = 1;i<=sqrt(n);i++){          // checking for all possible no
            minm = min(minm, helper(n-(i*i),dp));      
        }
        return dp[n] =  minm + 1;       // adding the 1 to keep the count
    }
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return helper(n,dp);
    }
};