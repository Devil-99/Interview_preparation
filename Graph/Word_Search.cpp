#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<char>>& board, string word, int idx, int i, int j){
    if(idx==word.size())
    return true;
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='*' || board[i][j]!=word[idx])
    return false;

    char c=board[i][j];
    board[i][j]='*';
    bool top = dfs(board,word,idx+1,i-1,j);
    bool bottom = dfs(board, word, idx+1,i+1,j);
    bool right = dfs(board,word,idx+1,i,j+1);
    bool left = dfs(board,word,idx+1,i,j-1);
    
    board[i][j]=c;
    return top||bottom||right||left;
}

bool exist(vector<vector<char>>& board, string word) {
    int idx=0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++)
            if(board[i][j]==word[idx])
                if(dfs(board,word,idx,i,j))
                    return true;
    }
    return false;
}

int main(){
    vector<vector<char>> board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word="ABCCED";
    if(exist(board,word))
    cout<<"True";
    else
    cout<<"False";
}