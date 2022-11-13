class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i = 1;i<m;i++){
            vector<int> temp(n,-1);
            temp [0] = 1;           // for first col there is only 1 way to reach it
            for(int j = 1;j<n;j++){
                int top = 0, left = 0;
                top = dp[j];           // dp array is keepint track of prev row
                left = temp[j-1];       
                temp[j] = top + left;
            }
            dp = temp;
        }
        return dp[n-1];
    }
};