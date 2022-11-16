class Solution {
public:
    int solve(vector<vector<int>> &grid, int i, int j1, int j2, vector<vector<vector<int>>> &dp){
        if(j1== grid[0].size() || j2 == grid[0].size() || j1<0 || j2<0 || i == grid.size()){
            return 0;
        }
        if(i == grid.size()-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int ans = 0;
        for(int dj1 = -1;dj1<2;dj1++){
            for(int dj2 = -1;dj2<2;dj2++){
                ans = max(ans,solve(grid,i+1,j1+dj1,j2+dj2,dp));
            }
        }
        if(j1 == j2) ans += grid[i][j1];
        else ans += grid[i][j1] + grid[i][j2];
        return dp[i][j1][j2] = ans ;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return solve(grid,0,0,n-1,dp);
        return 0;
    }
};