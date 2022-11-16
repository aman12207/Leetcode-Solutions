class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,0)));
        for(int j1 = 0;j1<n;j1++){          // handling the base case;
            for(int j2 = 0;j2<n;j2++){
                if(j1 == j2) dp[m-1][j1][j2] = grid[m-1][j1];       // if it shares the same index count only once
                else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];       
            }
        }
        for(int i= m-2;i>=0;i--){
            for(int j1 = 0;j1<n;j1++){
                for(int j2 =0;j2<n;j2++){
                    int ans = 0;
                    for(int dj1 = -1;dj1<2;dj1++){      // check for all possible 9 paths
                        for(int dj2 = -1;dj2<2;dj2++){
                            int value = 0;
                            if(j1+dj1 >=0 && j1+dj1 < n && j2+dj2>=0 && j2+dj2 < n)
                            {
                                if(j1 == j2) value = grid[i][j1];  // if it shares the same index count only once
                                else value = grid[i][j1] + grid[i][j2];
                                ans = max(ans,dp[i+1][j1+dj1][j2+dj2] + value);
                            }   
                        }
                    }
                    dp[i][j1][j2] = ans ;
                }
            }
        }
        return dp[0][0][n-1];
    }
};