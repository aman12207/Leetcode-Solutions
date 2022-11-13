class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int x, int y,vector<vector<int>> &dp){      // actually we are doing the opp we are trying to reach 0 0  from m-1, n-1
        if(x<0 || y<0)         // base cases
            return 0;
        if(obstacleGrid[x][y] == 1) return 0;       // if obstacle return 0
        if(x== 0 && y == 0){                // found ans 
            return 1;
        }
        if(dp[x][y] != -1) return dp[x][y];
        int top = solve(obstacleGrid,x-1,y,dp);
        int left = solve(obstacleGrid,x,y-1,dp);        // calls
        return dp[x][y] = top + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(obstacleGrid, n-1,m-1,dp);
        
    }
};