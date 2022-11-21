class Solution {
public:
    bool isValid(int x, int y, int n, int m ){
        if(x<0 || y<0 || x == n || y == m) return false;
        return true;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int ans = 0;
        int n = maze.size(), m = maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        q.push({-1,-1});
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();                       // pop the initial element and search for all possible neighbours
            if(!(x == entrance[0] && y == entrance[1]) && (x == n-1 || y == m-1 || y == 0 || x == 0) ) {
                cout<<"return ";
                return ans;
            }
            if(x == -1 && y == -1){
              if(!q.empty()){       // if we don't write this condition it will turn into infinite loop
                  ans++;          // another level traverses
                  q.push({-1,-1});        // set the mark for next level
              }
            }
            if(isValid(x+1,y,n,m) && maze[x+1][y] == '.'){            // all four possilbe neighbours
                q.push({x+1,y});
                maze[x+1][y] = '+';                 // mark it as soon as u push it into queue
            }
            if(isValid(x,y+1,n,m) && maze[x][y+1] == '.'){
                q.push({x,y+1});
                maze[x][y+1] = '+';
            }
            if(isValid(x-1,y,n,m) && maze[x-1][y] == '.'){
                q.push({x-1,y});
                maze[x-1][y] = '+';
            }
            if(isValid(x,y-1,n,m) && maze[x][y-1] == '.'){
                q.push({x,y-1});
                maze[x][y-1] = '+';
            }
        }
        return -1;
    }
};