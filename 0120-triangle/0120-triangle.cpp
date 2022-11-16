class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp;
        for(int i = 0;i<m;i++){         // creating dp array of same size as triangle
            dp.push_back(vector<int>(i+1, -1));
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<=i;j++){
                if(i == 0 && j == 0){           // handling base case
                    dp[i][j] = triangle[0][0];
                    continue;
                }
                int topLeft = INT_MAX, top = INT_MAX;
                if(i>0 && j>0) topLeft = dp[i-1][j-1];          // we can choose from topleft and left
                if(j != i) top = dp[i-1][j];
                dp[i][j] = min(top,topLeft) + triangle[i][j];
            }
        }
        int ans = INT_MAX;
        for(auto i : dp[m-1]){          // any of the last row might be our answer so we have to check for all of them
            ans = min(ans,i);
        }
        return ans;
    }
};