class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // just replace dp[n-1][j] with dp[j] as dp is storing prev row
        // dp[n][j] with curr [j] as it is keeping track of curr row
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n,0);
        for(int i = 0;i<m;i++){
            vector<int> curr(n,0);
            for(int j = 0;j<n;j++){
                if(i == 0 && j == 0) {      // base case
                    curr[j] = grid[0][0];
                    continue;
                }
                int top = INT_MAX, left = INT_MAX;          // if one of them doesn't exist we have to chooose other
                if(i>0) top = dp[j];
                if(j>0) left = curr[j-1];
                curr[j] = min(top , left) + grid[i][j];
            }
            dp = curr;
        }
        return dp[n-1];
    }
};