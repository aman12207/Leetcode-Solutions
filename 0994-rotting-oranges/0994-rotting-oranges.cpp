class Solution {
public:
    bool isValid(int x, int y, int n, int m ){
        if(x<0 || y<0 || x == n || y == m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0 ;i<n;i++){            // insert all rotten oranges which are intially in the grid
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        q.push({-1,-1});        // to keep the track of levels
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();                                // pop the initial element and search for all possible neighbours
            if(x == -1 && y == -1){
                if(!q.empty()){  
                    ans++;          // another level traverses
                    q.push({-1,-1});        // set the mark for next level
                }
            }
            if(isValid(x+1,y,n,m) && grid[x+1][y] == 1){            // all four possilbe neighbours
              q.push({x+1,y});
              grid[x+1][y] = 2;
            }
            if(isValid(x,y+1,n,m) && grid[x][y+1] == 1){
              q.push({x,y+1});
              grid[x][y+1] = 2;
            }
            if(isValid(x-1,y,n,m) && grid[x-1][y] == 1){
              q.push({x-1,y});
              grid[x-1][y] = 2;
            }
            if(isValid(x,y-1,n,m) && grid[x][y-1] == 1){
              q.push({x,y-1});
              grid[x][y-1] = 2;
            }
        }
        for(auto i : grid){         // if any of the orange is not rotten return -1;
            for(auto j : i) 
                if(j == 1) return -1;
        }
        return ans ;
    }
};