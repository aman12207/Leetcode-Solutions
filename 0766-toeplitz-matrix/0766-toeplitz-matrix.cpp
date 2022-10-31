class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i =0;i<n;i++){
            int j = i,k=0, temp = matrix[i][0];
            while(j<n && k<m){
                if(temp!= matrix[j][k]) return false;
                // cout<<matrix[j][k]<<' ';
                j++;
                k++;
            }
        }
        for(int i =0;i<m;i++){
            int j = 0,k=i, temp = matrix[0][i];
            while(j<n && k<m){
                if(temp!= matrix[j][k]) return false;
                // cout<<matrix[j][k]<<' ';
                j++;
                k++;
            }
        }
        return true;
    }
};