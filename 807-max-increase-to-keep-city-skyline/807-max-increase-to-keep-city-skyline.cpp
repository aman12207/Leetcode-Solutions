class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> maxCol,maxRow;
        int n = grid.size();
        int sum = 0;
        for(int i =0;i<n;i++){
            int maxrow,maxcol;
            maxrow = maxcol = INT_MIN;
            for(int j = 0;j<n;j++){
                maxrow = max(maxrow,grid[i][j]);
                maxcol = max(maxcol,grid[j][i]);
                sum += grid[i][j];
            }
            maxRow.push_back(maxrow);
            maxCol.push_back(maxcol);
        }
        int finalSum = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                finalSum += min(maxRow[i],maxCol[j]);
            }
        }
        return finalSum-sum;
    }
};