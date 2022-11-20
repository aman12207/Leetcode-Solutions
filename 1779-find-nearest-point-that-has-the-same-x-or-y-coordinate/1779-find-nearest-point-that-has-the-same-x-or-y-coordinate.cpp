class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int index = -1, dist = INT_MAX , n = points.size();
        for(int i = 0;i<n;i++){
            if(x == points[i][0] || y == points[i][1]){
                int currx = abs(x - points[i][0]), curry = abs(y - points[i][1]);
                if(dist> currx + curry){
                    dist = currx + curry;
                    index = i;
                }
            }
        }
        return index;
    }
};