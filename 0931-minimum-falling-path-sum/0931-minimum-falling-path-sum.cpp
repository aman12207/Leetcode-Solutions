class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> prev(n,-1);
        int ans =  INT_MAX;
        for(int i = 0;i<m;i++){
            vector<int> curr(n,-1);
            for(int j = 0 ;j<n;j++){
                if(i == 0 ){                // base case
                    curr[j] = matrix[i][j] ;
                    continue;
                }
                int top = INT_MAX, topleft = INT_MAX, topright = INT_MAX;
                top = prev[j];
                if(j>0 )topleft = prev[j-1];        // calls
                if(j<m-1) topright = prev[j+1];
                curr[j] = min(top, min(topleft,topright)) + matrix[i][j];
            }
            prev = curr;
        }
        for(auto i : prev){          // find the minm possilbe ans
            ans = min(ans,i);
        }
        return ans;
    }
};