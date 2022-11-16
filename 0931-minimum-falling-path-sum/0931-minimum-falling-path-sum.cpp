class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        int ans =  INT_MAX;
        for(int i = 0;i<m;i++){
            for(int j = 0 ;j<n;j++){
                if(i == 0 ){                // base case
                    dp[i][j] = matrix[i][j] ;
                    continue;
                }
                int top = INT_MAX, topleft = INT_MAX, topright = INT_MAX;
                top = dp[i-1][j];
                if(j>0 )topleft = dp[i-1][j-1];        // calls
                if(j<m-1) topright = dp[i-1][j+1];
                dp[i][j] = min(top, min(topleft,topright)) + matrix[i][j];
            }
        }
        for(auto i : dp[m-1]){          // find the minm possilbe ans
            ans = min(ans,i);
        }
        return ans;
    }
};