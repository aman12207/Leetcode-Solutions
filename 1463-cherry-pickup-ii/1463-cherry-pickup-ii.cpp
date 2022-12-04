class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j1, int j2,  vector<vector<vector<int>>> &dp){
        if(i == grid.size() || j1 == grid[0].size() || j2 == grid[0].size() || j1 < 0 || j2<0){ // base conditions
            return 0;
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int currAns = INT_MIN;
        for(int dj1 = -1;dj1<2;dj1++){      // check for all possible combinations
            for(int dj2 = -1;dj2<2;dj2++){
                currAns = max(currAns, solve(grid,i+1, j1 + dj1, j2 + dj2, dp));
            }
        }
        if(j1 == j2) currAns += grid[i][j1];       // cherries can only be picked by one robot
        else currAns += grid[i][j1] + grid[i][j2];
        return dp[i][j1][j2] = currAns;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
	    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        for(int j1 = 0;j1<n;j1++){          // handling the base case;
            for(int j2 = 0;j2<n;j2++){
                if(j1 == j2) dp[m-1][j1][j2] = grid[m-1][j1];       // if it shares the same index count only once
                else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];       
            }
        }
        for(int i = m-2;i>=0;i--){
            for(int j1 = 0;j1<n;j1++){
                for(int j2 = 0;j2<n;j2++){
                    int currAns = INT_MIN;
                    for(int dj1 = -1;dj1<2;dj1++){      // check for all possible combinations
                        for(int dj2 = -1;dj2<2;dj2++){
                            if(j1 + dj1>=0 && j1 + dj1 <n && j2+ dj2 >=0 && j2 + dj2 < n)
                            currAns = max(currAns, dp[i+1][j1+dj1][j2+dj2]);
                        }
                    }
                    if(j1 == j2) currAns += grid[i][j1];       // cherries can only be picked by one robot
                    else currAns += grid[i][j1] + grid[i][j2];
                    dp[i][j1][j2] = currAns;
                }
            }
        }
        return dp[0][0][n-1];
    }
};