class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i , int j , vector<vector<int>>&dp){
        if(i == triangle.size()-1){     // there is no edge case as for every element bottom and bottom right node will be available except last row
            return triangle[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int down  = solve(triangle,i+1,j,dp);
        int downright  = solve(triangle,i+1,j+1,dp);
        return dp[i][j] = min(down,downright) + triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(triangle,0,0,dp);
    }
};