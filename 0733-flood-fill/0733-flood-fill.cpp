class Solution {
public:
    bool isValid(int x, int y, int n, int m ){
        if(x<0 || y<0 || x == n || y == m) return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int n = image.size(), m = image[0].size();
        q.push({sr,sc});
        int initialColor = image[sr][sc];
        if(initialColor == color) return image;
        image[sr][sc] = color;
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            if(isValid(x+1,y,n,m) && image[x+1][y] == initialColor){
                q.push({x+1,y});
                image[x+1][y] = color;
            }
            if(isValid(x,y+1,n,m) && image[x][y+1] == initialColor){
                q.push({x,y+1});
                image[x][y+1] = color;
            }
            if(isValid(x-1,y,n,m) && image[x-1][y] == initialColor){
                q.push({x-1,y});
                image[x-1][y] = color;
            }
            if(isValid(x,y-1,n,m) && image[x][y-1] == initialColor){
                q.push({x,y-1});
                image[x][y-1] = color;
            }
        }
        return image;
    }
};