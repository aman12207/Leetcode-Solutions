class Solution {
public:
    int solve(int x, int y,vector<vector<int>> &dp){      // actually we are doing the opp we are trying to reach 0 0  from m-1, n-1
        if(x== 0 && y == 0){                // found ans 
            return 1;
        }
        if(x<0 || y<0)         // base cases
            return 0;
        if(dp[x][y] != -1) return dp[x][y];
        int top = solve(x-1,y,dp);
        int left = solve(x,y-1,dp);        // calls
        return dp[x][y] = top + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};