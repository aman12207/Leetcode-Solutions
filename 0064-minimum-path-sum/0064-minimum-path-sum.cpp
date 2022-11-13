class Solution {
public:
        int solve(vector<vector<int>>& grid,int x, int y,vector<vector<int>> &dp){      // actually we are doing the opp we are trying to reach 0 0  from m-1, n-1
        if(x== 0 && y == 0){                // found ans 
            return grid[0][0];
        }
        if(x<0 || y<0)         // base cases
            return INT_MAX;
        if(dp[x][y] != -1) return dp[x][y];
        int top = solve(grid,x-1,y,dp) ;
        int left = solve(grid,x,y-1,dp);        // calls
        return dp[x][y] = min(top, left) + grid[x][y];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(grid,m-1,n-1,dp);
    }
};