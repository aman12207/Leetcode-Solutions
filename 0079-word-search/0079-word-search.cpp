class Solution {
public:
    bool helper(vector<vector<char>>& board, int i , int j, string word, string curr){
        if(word.size() == curr.size()){
            if(word == curr) return true;
            return false;
        }
        if(board[i][j] == ' ') return false;
        if(word[curr.size()-1] != board[i][j]) return false;                // if it is not same as ith char of word don't take it
        char temp = board[i][j];
        board[i][j] = ' ';
        if(i<board.size()-1){
            curr.push_back(board[i+1][j]);
            bool top =  helper(board,i+1,j,word,curr);          //just check in all possilble direction if find no need to search any further
            if(top) return true;
            curr.pop_back();
        }
        if(j<board[0].size()-1){
            curr.push_back(board[i][j+1]);
            bool right =  helper(board,i,j+1,word,curr);
            if(right) return true;
            curr.pop_back();
        }
        if(i>0){
            curr.push_back(board[i-1][j]);
            bool bottom =  helper(board,i-1,j,word,curr);
            if(bottom) return true;
            curr.pop_back();
        }
        if(j>0){
            curr.push_back(board[i][j-1]);
            bool left =  helper(board,i,j-1,word,curr);
            if(left) return true;
            curr.pop_back();
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                string curr = "";
                curr.push_back(board[i][j]);
                if(helper(board,i,j,word, curr)) return true;       // insert curr element and check for its adjacents through recursion
            }
        }
        return false;
    }
};