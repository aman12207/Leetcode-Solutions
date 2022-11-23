class Solution {
public:
    int lcs(string text1, string text2, int i , int j ,vector<vector<int>>&dp){
        if(i == -1 || j == -1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]){
            return dp[i][j] = lcs(text1,text2,i-1,j-1,dp)+ 1;
        }
        return dp[i][j]= max(lcs(text1,text2, i,j-1,dp), lcs(text1,text2,i-1,j,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));      // we have to shift index becuase we can't handle -1case here
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1]+ 1;
                else
                    dp[i][j]= max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
};