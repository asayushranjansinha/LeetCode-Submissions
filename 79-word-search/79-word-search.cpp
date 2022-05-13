class Solution {
    bool helperDFS(int index,int i,int j,string &word,
                  vector<vector<char>> &board,
                  vector<vector<bool>> &vis){
        
        if(index == word.size()){
            return true;
        }else if(i < 0 || j < 0 || i == board.size() || j == board[0].size() || vis[i][j] == true){
            return false;
        }else if(word[index] != board[i][j]){
            return false;
        }
        
        vis[i][j] = true;
        if( helperDFS(index+1,i-1,j,word,board,vis) ||
            helperDFS(index+1,i,j+1,word,board,vis) || 
            helperDFS(index+1,i+1,j,word,board,vis) ||
            helperDFS(index+1,i,j-1,word,board,vis) ){
            
            return true;
        }
        
        vis[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(word[0] == board[i][j]){
                    vector<vector<bool>> vis(board.size(),vector<bool>(vector<bool>                                                                               (board[0].size(),false)));
                    
                    if(helperDFS(0,i,j,word,board,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};