class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> prev(m,-1);
        for(int i = 0;i<m;i++){
            vector<int> curr (i+1, -1);           // each row have same no of col as row no
            for(int j = 0;j<=i;j++){
                if(i == 0 && j == 0){           // handling base case
                    curr[j] = triangle[0][0];
                    continue;
                }
                int topLeft = INT_MAX, top = INT_MAX;
                if(i>0 && j>0) topLeft = prev[j-1];          // we can choose from topleft and left
                if(j != i) top = prev[j];
                curr[j] = min(top,topLeft) + triangle[i][j];
            }
            prev = curr;
        }
        int ans = INT_MAX;
        for(auto i : prev){          // any of the last row might be our answer so we have to check for all of them
            ans = min(ans,i);
        }
        return ans;
    }
};