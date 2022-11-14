class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n,0);        // it keeps track of prev row
        for(int i = 0;i<m;i++){
            vector<int> curr(n,0);      // it keeps track of curr row
            for(int j = 0;j<n;j++){
                if(obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                }         // if it is an obstacle mark it as 0 as there is no way to reach that block
                // if grid is 0 1 0 0 as we are adding top and left 
                // the dp will be 1 0 0 0 a
                else if(i == 0 && j == 0) curr[j] = 1;
                else {
                    int top = 0, left = 0;
                    if(i>0) top = dp[j];
                    if(j>0 ) left = curr[j-1];
                    curr[j] = top + left;
                }
            }
            dp = curr;
        }
        return dp[n-1];
    }
};