class Solution {
public:
    int solve(vector<vector<int>> &visited, int x, int y,vector<vector<int>> &dp){      // actually we are doing the opp we are trying to reach 0 0  from m-1, n-1
        if(x== 0 && y == 0){                // found ans 
            return 1;
        }
        if(x<0 || y<0)         // base cases
            return 0;
        if(visited[x][y]) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        visited[x][y] = 1;              // marking
        int top = solve(visited,x-1,y,dp);
        int left = solve(visited,x,y-1,dp);        // calls
        visited[x][y] = 0;              // backtracking
        return dp[x][y] = top + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> visited(m, vector<int>(n,0));
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(visited,m-1,n-1,dp);
    }
};