class Solution {
public:
    int solve(vector<vector<int>>& grid,int x, int y,vector<vector<int>> &dp){      // actually we are doing the opp we are trying to reach 0 0  from m-1, n-1
        if(x== 0){                // found ans 
            return dp[x][y] = grid[x][y];
        }
        if(dp[x][y] != -1) return dp[x][y];
        int top = INT_MAX, topleft = INT_MAX, topright = INT_MAX;
        top = solve(grid,x-1,y,dp) ;
        if(y>0 )topleft = solve(grid,x-1,y-1,dp);        // calls
        if(y<grid[0].size()-1) topright = solve(grid, x-1,y+1,dp);
        return dp[x][y] = min(top, min(topleft,topright)) + grid[x][y];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        int ans =  INT_MAX;
        for(int i = 0;i<n;i++){
            ans = min(ans,solve(matrix,m-1,i,dp));
        }
        return ans;
    }
};